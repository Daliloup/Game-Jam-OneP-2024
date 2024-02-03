//
// Created by sanch on 03/02/2024.
//

#include "Chouette.h"

#include <raylib.h>
#include <nlohmann/json.hpp>

#include "../globals.h"

Chouette::Chouette(Vector2 position) : Object(position) {
    m_velocity = {0, 0};
    m_acceleration = {0, 0};
    texture = g_textures["chouette"];
}

Chouette::Chouette(nlohmann::json json_object) : Object(json_object) {
    //DO stuff here ?
    texture = g_textures["chouette"];
}

void Chouette::Update() {
    Object::Update();
}

void Chouette::Draw() {
    DrawTexturePro(*texture, {0, 0, 32, 32},
                   {m_hitbox.x, m_hitbox.y, 32, 32},
                   {0, 0}, 0, WHITE);
}

Object *Chouette::Construct(nlohmann::json json_object) {
    return new Chouette(std::move(json_object));
}
