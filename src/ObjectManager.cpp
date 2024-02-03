//
// Created by sanch on 03/02/2024.
//

#include "ObjectManager.h"
#include "Object.h"

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
