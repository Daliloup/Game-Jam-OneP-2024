//
// Created by sanch on 03/02/2024.
//

#include "Chouette.h"
#include <raylib.h>

void Chouette::Update() {
    Object::Update();
}

void Chouette::Draw() {
    DrawTexturePro(*texture, {0, 0, 32, 32}, {m_position.x, m_position.y, 32, 32}, {0, 0}, 0, WHITE);

}

Chouette::Chouette(Vector2 position, Texture *tex) : Object(position) {
    m_velocity = {0, 0};
    m_acceleration = {0, 0};
    texture = tex;
}
