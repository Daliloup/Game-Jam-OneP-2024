#ifndef CHOUETTE_TILELAYER_H
#define CHOUETTE_TILELAYER_H

#include "Layer.h"

class Tileset;

class TileLayer : public Layer {
public:
    TileLayer(nlohmann::json layer_json);
    ~TileLayer() override;

    void Draw() override;
private:
    short *m_data;
    Tileset *m_tileset;
};


#endif //CHOUETTE_TILELAYER_H
