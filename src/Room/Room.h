
#ifndef CHOUETTE_ROOM_H
#define CHOUETTE_ROOM_H

#include "../State.h"

#include <string>
#include <vector>
#include <raylib.h>

class Layer;

class Room : public State {
public:
    Room(const char *filename);
    ~Room() override;

    void Update() override;
    void Draw() override;

    bool CheckCollisionsTiles(Rectangle rec, short tile_to_check, std::string layer_name);
    Layer *GetLayer(std::string layer_name);

private:
    std::vector<Layer *> m_layers;
};


#endif //CHOUETTE_ROOM_H
