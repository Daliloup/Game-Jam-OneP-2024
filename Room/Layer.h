#ifndef CHOUETTE_LAYER_H
#define CHOUETTE_LAYER_H

#include <nlohmann/json_fwd.hpp>
#include <string>

class Room;

class Layer {
public:
    Layer(nlohmann::json layer_json);
    virtual ~Layer();

    virtual void Update();
    virtual void Draw();

protected:
    std::string m_name;
    int m_offset_x, m_offset_y;
    int m_grid_cell_width, m_grid_cell_height;
    int m_grid_cells_x, m_grid_cells_y;
};


#endif //CHOUETTE_LAYER_H
