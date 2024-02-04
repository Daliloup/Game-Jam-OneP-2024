#include "TileLayer.h"
#include "nlohmann/json.hpp"

#include "../globals.h"
#include "../Tileset.h"

TileLayer::TileLayer(nlohmann::json layer_json) : Layer(layer_json) {
    m_type = LayerType::LayerType_Tiles;

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
    if(m_tileset == nullptr) return;

    //Layer::Draw();
    int painter_x = m_offset_x;
    int painter_y = m_offset_y;

    for(int y = 0; y < m_grid_cells_y; ++y) {
        for(int x = 0; x < m_grid_cells_x; ++x) {
            m_tileset->DrawTile(m_data[x+y*m_grid_cells_x], painter_x, painter_y);
            painter_x += m_grid_cell_width;
        }
        painter_x = m_offset_x;
        painter_y += m_grid_cell_height;
    }
}

bool TileLayer::CheckCollision(Rectangle rec, int value_to_check) {
    if(rec.x + rec.width < (float)m_offset_x ||
       rec.y+rec.height < (float)m_offset_y ||
       rec.x >= (float)(m_offset_x+m_grid_cell_width*m_grid_cells_x) ||
       rec.y >= (float)(m_offset_y+m_grid_cell_height*m_grid_cells_y)) return false;

    int x_begin = ((int)rec.x - m_offset_x) / m_grid_cell_width;
    int x_end = ((int)(rec.x+rec.width-1) - m_offset_x) / m_grid_cell_width;

    int y_begin = ((int)rec.y - m_offset_y) / m_grid_cell_height;
    int y_end = ((int)(rec.y+rec.height-1) - m_offset_y) / m_grid_cell_height;

    if(x_begin < 0) x_begin = 0;
    if(x_end >= m_grid_cells_x) x_end = m_grid_cells_x-1;
    if(y_begin < 0) y_begin = 0;
    if(y_end >= m_grid_cells_y) y_end = m_grid_cells_y-1;

    for(int y = y_begin; y <= y_end; ++y) {
        for(int x = x_begin; x <= x_end; ++x) {
            if(GetTile(x, y) == value_to_check) return true;
        }
    }
    return false;
}

/**
 *
 * @param x x index of tile
 * @param y y index of tile
 * @return value of time
 */
short TileLayer::GetTile(int x, int y) {
    if(x < 0 || y < 0 || x >= m_grid_cells_x || y >= m_grid_cells_y) return -1;
    return m_data[x+y*m_grid_cells_x];
}