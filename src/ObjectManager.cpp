//
// Created by sanch on 03/02/2024.
//

#include "ObjectManager.h"
#include "Object.h"
#include <algorithm>
#include <raylib.h>

ObjectManager::ObjectManager() {
    m_layer = nullptr;
}

ObjectManager::~ObjectManager() {
    for (Object *object : objects) {
        delete object;
    }
}

void ObjectManager::Update() {
    for (Object *object : objects) {
        object->Update();
    }
}

void ObjectManager::Draw() {
    for (Object *object : objects) {
        object->Draw();
    }
}

void ObjectManager::AddObject(Object *object) {
    object->SetObjectManager(this);
    objects.push_back(object);
}

void ObjectManager::RemoveObject(Object *object) {
    auto find_result = std::find(objects.begin(), objects.end(),object);
    if(find_result == objects.end()) return;
    objects.erase(find_result);
}

void ObjectManager::DestroyObject(Object *object) {
    auto find_result = std::find(objects.begin(), objects.end(),object);
    if(find_result == objects.end()) return;
    objects.erase(find_result);
    delete object;
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

std::vector<Object *> ObjectManager::ObjectCollisionsList(Object *object, int target_id) {
    std::vector<Object *> collisions = {};
    for (Object *object2 : objects) {
        if ((object != object2) && (object2->ID() == target_id) &&
            (CheckCollisionRecs(object->GetHitbox(), object2->GetHitbox()))) {
            collisions.push_back(object2);
        }
    }
    return collisions;
}

std::vector<Object *> ObjectManager::ObjectList(int target_id) {
    std::vector<Object *> r = {};
    for (Object *object2 : objects) {
        if (object2->ID() == target_id) {
            r.push_back(object2);
        }
    }
    return r;
}

void ObjectManager::SetLayer(ObjectLayer *layer) {
    m_layer = layer;
}

ObjectLayer *ObjectManager::GetLayer() {
    return m_layer;
}
