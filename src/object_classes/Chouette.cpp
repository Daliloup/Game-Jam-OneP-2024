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
    m_hitbox.y += m_velocity.y;
    m_velocity.y += m_acceleration.y;
    HandleVerticalCollisions();

    m_hitbox.x += m_velocity.x;
    m_velocity.x += m_acceleration.x;
    HandlsHorizontalCollisions();
}

void Chouette::Draw() {
    DrawTexturePro(*texture, {0, 0, 32, 32},
                   {m_hitbox.x, m_hitbox.y, 32, 32},
                   {0, 0}, 0, WHITE);
}

Object *Chouette::Construct(nlohmann::json json_object) {
    return new Chouette(std::move(json_object));
}

void Chouette::HandleVerticalCollisions() {
    std::vector<Object *> collisions = m_object_manager->ObjectCollisionsList(this);
    for (Object *object : collisions) {
        Rectangle hitbox = object->GetHitbox();
        if (((m_hitbox.y + m_hitbox.height) > hitbox.y) && (m_hitbox.y < hitbox.y)) {
            m_hitbox.y = hitbox.y - m_hitbox.height;
            m_velocity.y = 0;
        }
        else if ((m_hitbox.y < (hitbox.y + hitbox.height)) && (m_hitbox.y + m_hitbox.height > hitbox.y + hitbox.height)) {
            m_hitbox.y = hitbox.y + hitbox.height;
            m_velocity.y = 0;
        }
    }
}

void Chouette::HandlsHorizontalCollisions() {
    std::vector<Object *> collisions = m_object_manager->ObjectCollisionsList(this);
    for (Object *object : collisions) {
        Rectangle hitbox = object->GetHitbox();
        if (((m_hitbox.x + m_hitbox.width) > hitbox.x) && (m_hitbox.x < hitbox.x)) {
            m_hitbox.x = hitbox.x - m_hitbox.width;
            m_velocity.x = 0;
        }
        else if ((m_hitbox.x < (hitbox.x + hitbox.width)) && (m_hitbox.x + m_hitbox.width > hitbox.x + hitbox.width)) {

            m_hitbox.x = hitbox.x + hitbox.width;
            m_velocity.y = 0;
        }
    }
}
