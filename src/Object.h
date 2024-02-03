//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_OBJECT_H
#define CHOUETTE_OBJECT_H

#include "raylib.h"
#include <vector>
#include <nlohmann/json_fwd.hpp>
#include "ObjectManager.h"


class Object {
public:
    explicit Object(Vector2 position);
    explicit Object(nlohmann::json json_obect);
    virtual void Draw();
    virtual void Update();
    void SetPosition(Vector2 position);
    void SetVelocity(Vector2 velocity);
    void SetAcceleration(Vector2 acceleration);
    void SetObjectManager(ObjectManager *objectManager);
    Rectangle GetHitbox();

    static Object *Construct(nlohmann::json json_object);

protected:
    Rectangle m_hitbox;
    Vector2 m_velocity;
    Vector2 m_acceleration;

    ObjectManager *m_object_manager;
};

typedef Object * (*ObjectConstructor) (nlohmann::json json_object);


#endif //CHOUETTE_OBJECT_H
