//
// Created by sanch on 03/02/2024.
//

#include "ObjectManager.h"
#include "Object.h"
#include <raylib.h>

ObjectManager::ObjectManager() {

}

void ObjectManager::Update() {
    for (Object *object : objects) {
        object->Update();
    }
}

void ObjectManager::AddObject(Object *object) {
    objects.push_back(object);
}

void ObjectManager::Draw() {
    for (Object *object : objects) {
        object->Draw();
    }
}

ObjectManager::~ObjectManager() {
    for (Object *object : objects) {
        delete object;
    }
}

std::vector<Object *> ObjectManager::ObjectCollisionsList(Object *object) {
    std::vector<Object *> collisions = {};
    for (Object *object2 : objects) {
        if ((object != object2) &&
            (CheckCollisionRecs(object->GetHitbox(), object2->GetHitbox()))) {
            collisions.push_back(object2);
        }
    }
    return collisions;
}
