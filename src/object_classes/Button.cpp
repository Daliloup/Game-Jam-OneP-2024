#include "Button.h"

#include "../globals.h"
#include "ObjectType.h"

#include <nlohmann/json.hpp>

Button::Button(nlohmann::json object_json) : Object(object_json) {
    m_key = object_json["values"]["key"];
    m_texture = g_textures["button"];
    m_id = ObjectType_Button;
}

void Button::Update() {
    if(m_object_manager == nullptr) return;

    if(g_values[m_key] == 1) {
        m_object_manager->DestroyObject(this);
        return;
    }


    if(!m_object_manager->ObjectCollisionsList(this, ObjectType_Chouette).empty()) {
        g_values[m_key] = 1;
    }
}

void Button::Draw() {
    DrawTexturePro(*m_texture, {0.f, 0.f, 8.f, 8.f}, m_hitbox, {0.f, 0.f}, 0.f, WHITE);
}

Object *Button::Construct(nlohmann::json json_object) {
    return new Button(std::move(json_object));
}

