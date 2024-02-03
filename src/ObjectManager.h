//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_OBJECTMANAGER_H
#define CHOUETTE_OBJECTMANAGER_H
#include <vector>

class Object;
class ObjectLayer;

class ObjectManager {
public:
    ObjectManager();
    ~ObjectManager();
    void Update();
    void Draw();
    void AddObject(Object *object);
    void RemoveObject(Object *object);
    void DestroyObject(Object *object);
    std::vector<Object *> ObjectCollisionsList(Object *object);
    void SetLayer(ObjectLayer *layer);
    ObjectLayer *GetLayer();
private:
    std::vector<Object *> objects;
    ObjectLayer *m_layer;
};


#endif //CHOUETTE_OBJECTMANAGER_H
