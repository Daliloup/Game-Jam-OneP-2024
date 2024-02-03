#ifndef CHOUETTE_OBJECTLAYER_H
#define CHOUETTE_OBJECTLAYER_H

#include "Layer.h"

class ObjectManager;

class ObjectLayer : public Layer {
public:
    ObjectLayer(nlohmann::json layer_json);
    ~ObjectLayer() override;

    void Update() override;
    void Draw() override;

private:
    ObjectManager *m_object_manager;
};


#endif //CHOUETTE_OBJECTLAYER_H
