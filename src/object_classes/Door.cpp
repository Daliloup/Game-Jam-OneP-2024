#include "Door.h"

#include <utility>

#include "nlohmann/json.hpp"

#include "../globals.h"

Door::Door(nlohmann::json json_obect) : Object(json_obect) {
    m_key = json_obect["values"]["key"];
    m_texture = g_textures["door_tile"];
    m_id = 4;
    m_open = g_values[m_key];
    m_hitbox.height = m_hitbox.height * (float)!m_open;
}

void Door::Update() {
    if(g_values[m_key] == 1) {
        m_open = true;
    }

    if(m_open) {
        m_hitbox.height -= 1.f;
        if(m_hitbox.height < 0.f) {
            m_object_manager->DestroyObject(this);
            return;
        }
    }
}

void Door::Draw() {
    DrawTexturePro(*m_texture, {0.f, 0.f, 8.f, 8.f}, m_hitbox, {0.f, 0.f}, 0.f, WHITE);
}

Object *Door::Construct(nlohmann::json json_obect) {
    return new Door(std::move(json_obect));
}
