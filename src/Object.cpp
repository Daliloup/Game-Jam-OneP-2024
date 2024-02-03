//
// Created by sanch on 03/02/2024.
//

#include "Object.h"
#include "raylib.h"

#include <nlohmann/json.hpp>
#include <utility>
#include <iostream>


Object::Object(Vector2 position) {
    m_id = 0;
    m_hitbox = {position.x, position.y, 32, 32};
    m_velocity = {0, 0};
    m_acceleration = {0, 0};
}

Object::Object(nlohmann::json json_object) {
    printf("Object::Object(json)\n");
    std::cout << json_object << "\n";
    if(json_object.contains("width") && json_object.contains("height")) {
        m_hitbox = {(float) json_object["x"], (float) json_object["y"], (float) json_object["width"], (float) json_object["height"]};
    }
    else {
        printf("OBJECT DON'T HAVE WIDTH AND HEIGHT >:(\n");
        m_hitbox = {(float) json_object["x"], (float) json_object["y"], 16.f, 16.f};
    }

    m_velocity = {0, 0};
    m_acceleration = {0, 0};
}

void Object::Update() {
    m_hitbox.y += m_velocity.y;
    m_velocity.y += m_acceleration.y;

    m_hitbox.x += m_velocity.x;
    m_velocity.x += m_acceleration.x;
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

Object *Object::Construct(nlohmann::json json_object) {
    return new Object(std::move(json_object));
}
Rectangle Object::GetHitbox() {
    return m_hitbox;
}

int Object::ID() {
    return m_id;
}

void Object::SetObjectManager(ObjectManager *objectManager) {
    m_object_manager = objectManager;
}
