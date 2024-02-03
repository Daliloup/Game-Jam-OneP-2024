#include "Tileset.h"

Tileset::Tileset(Texture *texture, int cell_width, int cell_height) {
    //TODO : null safety ?
    m_texture = texture;
    m_tile_width = cell_width;
    m_tile_height = cell_height;

    m_tile_count_x = texture->width / m_tile_width;
    m_tile_count_y = texture->height / m_tile_height;
    m_tile_count = m_tile_count_x*m_tile_count_y;
}

Tileset::~Tileset() {

}

void Tileset::DrawTile(int index, int x, int y) {
    if(index < 0 || index >= m_tile_count) return;
    int tile_x_index = index % m_tile_count_x;
    int tile_y_index = index / m_tile_count_x;

    int tile_x_pos = tile_x_index * m_tile_width;
    int tile_y_pos = tile_y_index * m_tile_height;

    DrawTexturePro(*m_texture,
                   {(float)tile_x_pos, (float)tile_y_pos, (float)m_tile_width, (float)m_tile_height},
                   {(float)x, (float)y, (float)m_tile_width, (float)m_tile_height},
                   {0.f, 0.f}, 0.f,
                   WHITE);
}


