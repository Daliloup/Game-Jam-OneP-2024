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
    m_type = LayerType::LayerType_Default;
    m_room = nullptr;
}

Layer::~Layer() = default;

void Layer::Update() {

}

void Layer::Draw() {

}

LayerType Layer::Type() {
    return m_type;
}

std::string Layer::Name() {
    return m_name;
}

Room *Layer::GetRoom() {
    return m_room;
}

void Layer::SetRoom(Room *room) {
    m_room = room;
}
