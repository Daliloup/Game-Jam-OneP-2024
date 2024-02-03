#include <iostream>
#include "raylib.h"

#include "ObjectManager.h"
#include "Object.h"
#include "Room/Room.h"
#include "Tileset.h"

#include <unordered_map>
#include <string>

std::unordered_map<std::string, Tileset *> g_tilesets;


int main() {
    InitWindow(960, 540, "window");
    SetTargetFPS(60);

    RenderTexture render = LoadRenderTexture(320, 180);

    Texture chouette_sprite = LoadTexture("sprites/chouette.png");
    Texture tileset_texture = LoadTexture("./sprites/tileset.png");
    Tileset ts(&tileset_texture, 8, 8);
    g_tilesets["dream"] = &ts;

    Room room("sprites/level1.json");
    ObjectManager om;


    while(!WindowShouldClose()) {
        //
        om.Update();

        room.Update();


        BeginTextureMode(render);
        ClearBackground(BLACK);
        room.Draw();
        DrawTexturePro(chouette_sprite, {0, 0, 32, 32}, {0, 0, 32, 32}, {0, 0}, 0, WHITE);
        om.Draw();
        //
        EndTextureMode();

        BeginDrawing();
        DrawTexturePro(render.texture, {0, 0, 320, -180}, {0, 0, 960, 540}, {0, 0}, 0, WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(tileset_texture);
    UnloadRenderTexture(render);
    CloseWindow();
    return 0;
}
