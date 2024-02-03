#ifndef GAME_JAM_ONEP_2024_TILESET_H
#define GAME_JAM_ONEP_2024_TILESET_H

#include "raylib.h"

class Tileset {
public:
    Tileset(Texture *texture, int cell_width, int cell_height);
    ~Tileset();

    void DrawTile(int index, int x, int y);

private:
    Texture *m_texture;
    int m_tile_width, m_tile_height;
    int m_tile_count_x, m_tile_count_y, m_tile_count;
};


#endif //GAME_JAM_ONEP_2024_TILESET_H
