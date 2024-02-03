//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_OBJECTMANAGER_H
#define CHOUETTE_OBJECTMANAGER_H
#include <vector>

class Object;

class ObjectManager {
public:
    ObjectManager();
    ~ObjectManager();
    void Update();
    void Draw();
    void AddObject(Object *object);
private:
    std::vector<Object *> objects;
};


#endif //CHOUETTE_OBJECTMANAGER_H
