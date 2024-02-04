#include "SleepingChouette.h"

#include "../globals.h"
#include "../Room/Room.h"
#include "../Room/ObjectLayer.h"
#include "../StateManager.h"
#include "../Tileset.h"
#include "Chouette.h"

SleepingChouette::SleepingChouette(Vector2 position) : Object(position) {
    m_hitbox = {position.x, position.y, 32.f, 32.f};
    m_id = 3;
    m_tileset = g_tilesets["chouette_sleeping"];
    m_anim_state = 0;
}

void SleepingChouette::Update() {
    ++m_anim_state;
    if(m_anim_state >= 60) m_anim_state = 0;

    if(m_object_manager == nullptr) return;

    if(!IsKeyPressed(KEY_D)) return;

    auto cols = m_object_manager->ObjectCollisionsList(this, 1);
    if(cols.size() > 0) {
        Room *current_room = m_object_manager->GetLayer()->GetRoom();
        std::string normal_name = current_room->FileName();
        normal_name = normal_name.substr(0, normal_name.size() -6) + ".json";
        printf("Going back to %s\n", normal_name.c_str());

        Room *normal_room = new Room(normal_name.c_str());
        ObjectLayer *objl = (ObjectLayer *) normal_room->GetLayer("objects");
        auto chouettes = objl->GetObjectManager()->ObjectList(1);
        while (chouettes.size() > 0) {
            objl->GetObjectManager()->DestroyObject(chouettes.back());
            chouettes.pop_back();
        }

        objl->GetObjectManager()->AddObject(new Chouette({(float)(int)m_hitbox.x, (float)(int)m_hitbox.y}, false));
        current_room->Manager()->SetState(normal_room);
    }
}

void SleepingChouette::Draw() {
    //DrawRectangleRec(m_hitbox, GREEN);
    m_tileset->DrawTile(m_anim_state / 20, (int)m_hitbox.x, (int)m_hitbox.y, {255, 255, 255, 127});
}
