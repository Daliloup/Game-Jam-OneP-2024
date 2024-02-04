
#ifndef CHOUETTE_ROOM_H
#define CHOUETTE_ROOM_H

#include "../State.h"

#include <string>
#include <vector>
#include <raylib.h>

class Layer;
class Object;

class Room : public State {
public:
    Room(const char *filename);
    ~Room() override;

    void Update() override;
    void Draw() override;

    bool CheckCollisionsTiles(Rectangle rec, short tile_to_check, std::string layer_name);
    Layer *GetLayer(std::string layer_name);
    std::string FileName();

    Object *GetFollowingObject();
    void SetFollowingObject(Object *obj);

private:
    std::vector<Layer *> m_layers;
    int m_width, m_height;
    std::string m_filename;
    Texture *m_bg;
    Camera2D m_camera;
    Object *m_following_object;
};


#endif //CHOUETTE_ROOM_H
