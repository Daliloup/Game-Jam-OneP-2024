#include "RoomTrigger.h"

#include <nlohmann/json.hpp>

#include "Chouette.h"
#include "../Room/ObjectLayer.h"
#include "../Room/Room.h"
#include "../StateManager.h"

RoomTrigger::RoomTrigger(nlohmann::json json_object) : Object(json_object) {
    m_id = 2;
    m_target_room = json_object["values"]["target_room"];
    m_target_x = json_object["values"]["target_x"];
    m_target_y = json_object["values"]["target_y"];
}

void RoomTrigger::Update() {
    auto cols = m_object_manager->ObjectCollisionsList(this, 1);
    if(cols.size() > 0) {
        Chouette *chouette = (Chouette *) cols[0];
        m_object_manager->RemoveObject(chouette);
        StateManager *state_manager = m_object_manager->GetLayer()->GetRoom()->Manager();

        chouette->SetPosition({(float)m_target_x, (float)m_target_y});
        chouette->SetCheckpointPosition({(float)m_target_x, (float)m_target_y});
        chouette->SetVelocity({0.f, 0.f});

        Room *new_room = new Room(m_target_room.c_str());
        ObjectLayer *object_layer = (ObjectLayer *) new_room->GetLayer("objects");

        //This is to remove the chouettes in the new room
        auto chouettes = object_layer->GetObjectManager()->ObjectList(1);
        while (chouettes.size() > 0) {
            object_layer->GetObjectManager()->DestroyObject(chouettes.back());
            chouettes.pop_back();
        }

        object_layer->GetObjectManager()->AddObject(chouette);
        state_manager->SetState(new_room);
        return;
    }
}

Object *RoomTrigger::Construct(nlohmann::json json_object) {
    return new RoomTrigger(json_object);
}
