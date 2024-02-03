#include "Layer.h"

#include "nlohmann/json.hpp"

Layer::Layer(nlohmann::json layer_json) {
    m_name = layer_json["name"];
    m_offset_x = layer_json["offsetX"];
    m_offset_y = layer_json["offsetY"];
    m_grid_cell_width = layer_json["gridCellWidth"];
    m_grid_cell_height = layer_json["gridCellHeight"];
    m_grid_cells_x = layer_json["gridCellsX"];
    m_grid_cells_y = layer_json["gridCellsY"];
}

Layer::~Layer() {

}

void Layer::Update() {

}

void Layer::Draw() {

}
