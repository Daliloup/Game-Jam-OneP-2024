#ifndef GAME_JAM_ONEP_2024_TILESET_H
#define GAME_JAM_ONEP_2024_TILESET_H

#include "raylib.h"

class Tileset {
public:
    Tileset(Texture *texture, int cell_width, int cell_height, bool unload_texture = false);
    ~Tileset();

    void DrawTile(int index, int x, int y);
    void DrawTile(int index, int x, int y, bool h_flip);
    void DrawTile(int index, int x, int y, Color c);

    Texture *GetTexture();

private:
    Texture *m_texture;
    int m_tile_width, m_tile_height;
    int m_tile_count_x, m_tile_count_y, m_tile_count;
    bool m_unload_texture;
};


#endif //GAME_JAM_ONEP_2024_TILESET_H
