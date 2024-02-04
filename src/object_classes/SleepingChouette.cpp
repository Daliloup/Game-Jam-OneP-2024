#include "SleepingChouette.h"

#include "../Room/Room.h"
#include "../Room/ObjectLayer.h"
#include "../StateManager.h"
#include "Chouette.h"

SleepingChouette::SleepingChouette(Vector2 position) : Object(position) {
    m_hitbox = {position.x, position.y, 32.f, 32.f};
    m_id = 3;
}

void SleepingChouette::Update() {
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
    DrawRectangleRec(m_hitbox, GREEN);
}
