#include <iostream>
#include <raylib.h>

int main() {
    InitWindow(960, 540, "window");

    RenderTexture render = LoadRenderTexture(320, 180);

    while(!WindowShouldClose()) {
        //

        BeginTextureMode(render);
        ClearBackground(BLACK);
        DrawLine(0, 0, 25, 32, WHITE);

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
