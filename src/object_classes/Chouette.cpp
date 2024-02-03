//
// Created by sanch on 03/02/2024.
//

#include "Chouette.h"

#include <raylib.h>
#include <nlohmann/json.hpp>

#include "../globals.h"
#include "../Room/ObjectLayer.h"
#include "../Room/TileLayer.h"
#include "../Room/Room.h"

Chouette::Chouette(Vector2 position) : Object(position) {
    m_velocity = {0, 0};
    m_acceleration = {0, 50.f};
    m_texture = g_textures["chouette"];
    m_enable_multijump = true;
    m_jump_power = 0.f;
}

Chouette::Chouette(nlohmann::json json_object) : Object(json_object) {
    //DO stuff here ?
    m_texture = g_textures["chouette"];
    m_acceleration = {0, .1f};
}

void Chouette::Update() {
    m_velocity.y += m_acceleration.y;
    HandleJump();
    m_hitbox.y += m_velocity.y;
    HandleVerticalCollisions();

    m_velocity.x += m_acceleration.x;
    m_velocity.x = (float)(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * 1.f;
    m_hitbox.x += m_velocity.x;
    HandleHorizontalCollisions();
}

void Chouette::Draw() {
    DrawTexturePro(*m_texture, {0, 0, 32, 32},
                   {(float)(int)m_hitbox.x, (float)(int)m_hitbox.y+1, 32, 32},
                   {0, 0}, 0, WHITE);
}

Object *Chouette::Construct(nlohmann::json json_object) {
    return new Chouette(std::move(json_object));
}

void Chouette::HandleVerticalCollisions() {
    TileLayer *tile_collisions = (TileLayer *) m_object_manager->GetLayer()->GetRoom()->GetLayer("collision");
    if(tile_collisions != nullptr) {
        float direction = ((m_velocity.y < 0) ? -1.f : 1.f);
        while (tile_collisions->CheckCollision(m_hitbox, 1)) {
            m_hitbox.y -= 1.f * direction;
            m_velocity.y = 0.f;
        }
    }

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

void Chouette::HandleHorizontalCollisions() {
    TileLayer *tile_collisions = (TileLayer *) m_object_manager->GetLayer()->GetRoom()->GetLayer("collision");
    if(tile_collisions != nullptr) {
        float direction = ((m_velocity.x < 0) ? -1.f : 1.f);
        while (tile_collisions->CheckCollision(m_hitbox, 1)) {
            m_hitbox.x -= 1.f * direction;
            m_velocity.x = 0.f;
        }
    }

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

void Chouette::HandleJump() {
    printf("%f\n", m_jump_power);
    bool grounded = Grounded();
    if(grounded) {
        m_jump_power = 3.0f;
    }
    else if(!m_enable_multijump) {   //and not grounded
        m_jump_power = 0.f;
    }

    if((int)m_jump_power > 0 && IsKeyPressed(KEY_SPACE)) {
        m_velocity.y -= m_jump_power;
        m_jump_power -= 1.f;
    }
}

bool Chouette::Grounded() {
    TileLayer *tile_collisions = (TileLayer *) m_object_manager->GetLayer()->GetRoom()->GetLayer("collision");
    m_hitbox.y += 1.0f;
    bool result = false;
    if(tile_collisions != nullptr) {
        result = tile_collisions->CheckCollision(m_hitbox, 1);
    }

    m_hitbox.y -= 1.0f;
    return result;
}
