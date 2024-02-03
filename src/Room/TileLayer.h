#ifndef CHOUETTE_TILELAYER_H
#define CHOUETTE_TILELAYER_H

#include "Layer.h"

#include <raylib.h>

class Tileset;

class TileLayer : public Layer {
public:
    TileLayer(nlohmann::json layer_json);
    ~TileLayer() override;

    void Draw() override;

    bool CheckCollision(Rectangle rec, int value_to_check);
    short GetTile(int x, int y);

private:
    short *m_data;
    Tileset *m_tileset;
};


#endif //CHOUETTE_TILELAYER_H
