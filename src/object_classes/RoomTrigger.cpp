#include "RoomTrigger.h"

#include <nlohmann/json.hpp>

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
        Object *chouette = cols[0];
        m_object_manager->RemoveObject(chouette);
        StateManager *state_manager = m_object_manager->GetLayer()->GetRoom()->Manager();

        chouette->SetPosition({(float)m_target_x, (float)m_target_y});

        Room *new_room = new Room(m_target_room.c_str());
        ObjectLayer *object_layer = (ObjectLayer *) new_room->GetLayer("objects");
        object_layer->GetObjectManager()->AddObject(chouette);
        state_manager->SetState(new_room);
        return;
    }
}

Object *RoomTrigger::Construct(nlohmann::json json_object) {
    return new RoomTrigger(json_object);
}
