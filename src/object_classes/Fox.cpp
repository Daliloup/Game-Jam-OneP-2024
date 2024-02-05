#include "Fox.h"

#include "../globals.h"
#include "../Tileset.h"
#include "../Room/ObjectLayer.h"
#include "../Room/Room.h"
#include "../Room/TileLayer.h"
#include "Chouette.h"
#include "ObjectType.h"

#include <nlohmann/json.hpp>

Fox::Fox(nlohmann::json object_json) : Object(object_json) {
    m_tileset = g_tilesets["fox"];
    m_anim_state = 0;
    m_id = ObjectType_Fox;
    m_acceleration = {0, .1f};
    m_velocity = {-.5f, 0.f};
}

void Fox::Update() {
    ++m_anim_state;
    if(m_anim_state >= 50) m_anim_state = 0;

    m_velocity.y += m_acceleration.y;
    m_hitbox.y += m_velocity.y;
    HandleVerticalCollisions();

    m_velocity.x += m_acceleration.x;
    m_hitbox.x += m_velocity.x;
    HandleHorizontalCollisions();

    auto cols = m_object_manager->ObjectCollisionsList(this, ObjectType_Chouette);
    if(!cols.empty()) {
        ((Chouette *)cols[0]) -> GetRekt();
    }
}

void Fox::Draw() {
    if(m_tileset != nullptr)
        m_tileset->DrawTile(m_anim_state / 5, (int)m_hitbox.x, (int)m_hitbox.y, m_velocity.x > 0.f);
}

void Fox::HandleVerticalCollisions() {
    TileLayer *tile_collisions = (TileLayer *) m_object_manager->GetLayer()->GetRoom()->GetLayer("collision");
    if(tile_collisions != nullptr) {
        float direction = ((m_velocity.y < 0) ? -1.f : 1.f);
        while (tile_collisions->CheckCollision(m_hitbox, 1)) {
            m_hitbox.y -= 1.f * direction;
            m_velocity.y = 0.f;
        }
    }

    std::vector<Object *> collisions = m_object_manager->ObjectCollisionsList(this, ObjectType_Door);
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

void Fox::HandleHorizontalCollisions() {
    printf("%f\n", m_velocity.x);
    TileLayer *tile_collisions = (TileLayer *) m_object_manager->GetLayer()->GetRoom()->GetLayer("collision");
    if(tile_collisions != nullptr) {
        bool is_col = tile_collisions->CheckCollision(m_hitbox, 1);
        float direction = ((m_velocity.x < 0) ? -1.f : 1.f);
        while (tile_collisions->CheckCollision(m_hitbox, 1)) {
            m_hitbox.x -= 1.f * direction;
        }
        if(is_col) {
            m_velocity.x = -m_velocity.x;
        }
    }


    std::vector<Object *> collisions = m_object_manager->ObjectCollisionsList(this, ObjectType_Door);
    for (Object *object : collisions) {
        Rectangle hitbox = object->GetHitbox();
        if (((m_hitbox.x + m_hitbox.width) > hitbox.x) && (m_hitbox.x < hitbox.x)) {
            m_hitbox.x = hitbox.x - m_hitbox.width;
            m_velocity.x = -m_velocity.x;
        }
        else if ((m_hitbox.x < (hitbox.x + hitbox.width)) && (m_hitbox.x + m_hitbox.width > hitbox.x + hitbox.width)) {
            m_hitbox.x = hitbox.x + hitbox.width;
            m_velocity.x = 0;
        }
    }

}

Object *Fox::Construct(nlohmann::json object_json) {
    return new Fox(std::move(object_json));
}
