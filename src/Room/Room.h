
#ifndef CHOUETTE_ROOM_H
#define CHOUETTE_ROOM_H

#include <vector>

class Layer;

class Room {
public:
    Room(const char *filename);
    ~Room();

    void Update();
    void Draw();

private:
    std::vector<Layer *> m_layers;
};


#endif //CHOUETTE_ROOM_H
