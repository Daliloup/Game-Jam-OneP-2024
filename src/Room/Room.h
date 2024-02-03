
#ifndef CHOUETTE_ROOM_H
#define CHOUETTE_ROOM_H

#include <string>
#include <vector>
#include <raylib.h>

class Layer;

class Room {
public:
    Room(const char *filename);
    ~Room();

    void Update();
    void Draw();

    bool CheckCollisionsTiles(Rectangle rec, short tile_to_check, std::string layer_name);
    Layer *GetLayer(std::string layer_name);

private:
    std::vector<Layer *> m_layers;
};


#endif //CHOUETTE_ROOM_H
