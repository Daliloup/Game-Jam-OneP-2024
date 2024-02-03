//
// Created by sanch on 03/02/2024.
//

#include "Object.h"
#include "raylib.h"


Object::Object(Vector2 position) {
    m_hitbox = {position.x, position.y, 32, 32};
    m_velocity = {0, 0};
    m_acceleration = {0, 0};
}

void Object::Update() {
    m_hitbox.x += m_velocity.x;
    m_hitbox.y += m_velocity.y;

    m_velocity.x += m_acceleration.x;
    m_velocity.y += m_acceleration.y;
}

void Object::Draw() {
    DrawRectangleRec({m_hitbox.x, m_hitbox.y, 20, 20}, RED);
}

void Object::SetPosition(Vector2 position) {
    m_hitbox.x = position.x;
    m_hitbox.y = position.y;
}

void Object::SetVelocity(Vector2 velocity) {
    m_velocity = velocity;
}

void Object::SetAcceleration(Vector2 acceleration) {
    m_acceleration = acceleration;
}

Rectangle Object::GetHitbox() {
    return m_hitbox;
}
