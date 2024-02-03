#include <iostream>
#include <raylib.h>
#include "ObjectManager.h"
#include "Object.h"


int main() {
    InitWindow(960, 540, "window");
    SetTargetFPS(60);

    RenderTexture render = LoadRenderTexture(320, 180);
    Texture chouette_sprite = LoadTexture("sprites/chouette.png");

    ObjectManager om;

    while(!WindowShouldClose()) {
        //
        om.Update();


        BeginTextureMode(render);
        ClearBackground(BLACK);
        DrawTexturePro(chouette_sprite, {0, 0, 32, 32}, {0, 0, 32, 32}, {0, 0}, 0, WHITE);
        om.Draw();
        //
        EndTextureMode();

        BeginDrawing();
        DrawTexturePro(render.texture, {0, 0, 320, -180}, {0, 0, 960, 540}, {0, 0}, 0, WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadRenderTexture(render);
    CloseWindow();
    return 0;
}
