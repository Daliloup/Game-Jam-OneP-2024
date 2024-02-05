#include "Bell.h"

#include "../globals.h"
#include "Chouette.h"
#include "ObjectType.h"

#include <nlohmann/json.hpp>

Bell::Bell(nlohmann::json json_obect) : Object(json_obect) {
    m_texture = g_textures["bell"];
    m_id = ObjectType_Bell;
}

void Bell::Update() {
    if(m_object_manager == nullptr) return;
    auto chouettes = m_object_manager->ObjectCollisionsList(this, ObjectType_Chouette);
    if(chouettes.empty()) return;

    ((Chouette *)chouettes[0])->SetCheckpointPosition({m_hitbox.x-8.f+9.f, m_hitbox.y-16.f+8.f});

    auto chouettes_sleeping = m_object_manager->ObjectList(ObjectType_SleepingChouette);
    if(chouettes_sleeping.empty()) return;

    chouettes_sleeping[0]->SetPosition({m_hitbox.x-8.f, m_hitbox.y-16.f});
}

void Bell::Draw() {
    if(m_texture != nullptr)
        DrawTexturePro(*m_texture, {0.f, 0.f, 16.f, 16.f}, m_hitbox, {0.f, 0.f}, 0.f, WHITE);
}

Object *Bell::Construct(nlohmann::json json_object) {
    return new Bell(std::move(json_object));
}
