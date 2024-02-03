#include "TileLayer.h"
#include "nlohmann/json.hpp"

#include "../globals.h"
#include "../Tileset.h"

TileLayer::TileLayer(nlohmann::json layer_json) : Layer(layer_json) {
    auto data = layer_json["data"];
    size_t data_len = data.size();

    m_data = (short *) malloc(data_len * sizeof(short));
    for(size_t i = 0; i < data_len; ++i) m_data[i] = data[i];

    std::string tileset_name = layer_json["tileset"];
    printf("Trying to load tileset %s\n", tileset_name.c_str());
    m_tileset = g_tilesets[layer_json["tileset"]];
}

TileLayer::~TileLayer() {
    free(m_data);
}

void TileLayer::Draw() {
    //Layer::Draw();
    int painter_x = m_offset_x;
    int painter_y = m_offset_y;

    for(int y = 0; y < m_grid_cells_y; ++y) {
        for(int x = 0; x < m_grid_cells_y; ++x) {
            m_tileset->DrawTile(m_data[x+y*m_grid_cells_x], painter_x, painter_y);
            painter_x += m_grid_cell_width;
        }
        painter_x = m_offset_x;
        painter_y += m_grid_cell_height;
    }
}
