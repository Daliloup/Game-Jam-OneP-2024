#ifndef CHOUETTE_OBJECTLAYER_H
#define CHOUETTE_OBJECTLAYER_H

#include <raylib.h>

#include "Layer.h"

class ObjectManager;

class ObjectLayer : public Layer {
public:
    ObjectLayer(nlohmann::json layer_json);
    ~ObjectLayer() override;

    void Update() override;
    void Draw() override;

    ObjectManager *GetObjectManager();

private:
    ObjectManager *m_object_manager;
};


#endif //CHOUETTE_OBJECTLAYER_H
