//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_OBJECT_H
#define CHOUETTE_OBJECT_H
#include "raylib.h"
#include <vector>


class Object {
public:
    explicit Object(Vector2 position);
    virtual void Draw();
    virtual void Update();
    void SetPosition(Vector2 position);
    void SetVelocity(Vector2 velocity);
    void SetAcceleration(Vector2 acceleration);
    Rectangle GetHitbox();

protected:
    Rectangle m_hitbox;
    Vector2 m_velocity;
    Vector2 m_acceleration;
};


#endif //CHOUETTE_OBJECT_H
