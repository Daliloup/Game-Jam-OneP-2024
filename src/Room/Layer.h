#ifndef CHOUETTE_LAYER_H
#define CHOUETTE_LAYER_H

#include "nlohmann/json_fwd.hpp"
#include <string>

class Room;

enum LayerType {
    LayerType_Default,
    LayerType_Tiles,
    LayerType_Objects
};

class Layer {
public:
    Layer(nlohmann::json layer_json);
    virtual ~Layer();

    virtual void Update();
    virtual void Draw();

    LayerType Type();
    std::string Name();

    Room *GetRoom();
    void SetRoom(Room *room);

protected:
    std::string m_name;
    int m_offset_x, m_offset_y;
    int m_grid_cell_width, m_grid_cell_height;
    int m_grid_cells_x, m_grid_cells_y;
    LayerType m_type;
    Room *m_room;
};


#endif //CHOUETTE_LAYER_H
