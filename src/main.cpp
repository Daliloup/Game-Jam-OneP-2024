#include <iostream>
#include "raylib.h"

#include "ObjectManager.h"
#include "Object.h"
#include "Room/Room.h"
#include "Tileset.h"
#include "object_classes/Chouette.h"
#include "object_classes/RoomTrigger.h"
#include "StateManager.h"
#include "GameOver.h"

#include <unordered_map>
#include <string>

std::unordered_map<std::string, Tileset *> g_tilesets;
std::unordered_map<std::string, Texture *> g_textures;
std::unordered_map<std::string, ObjectConstructor> g_object_constructors;


int main() {
    g_tilesets = std::unordered_map<std::string, Tileset *>();
    InitWindow(960, 540, "window");
    SetTargetFPS(60);

    RenderTexture render = LoadRenderTexture(320, 180);

    Texture chouette_sprite = LoadTexture("./sprites/chouette.png");
    g_textures["chouette"] = &chouette_sprite;

    Texture tileset_texture = LoadTexture("./sprites/tileset.png");
    Tileset ts(&tileset_texture, 8, 8);
    g_tilesets["dream"] = &ts;

    Texture background_lg = LoadTexture("./sprites/background_lg.png");

    g_object_constructors["chouette"] = Chouette::Construct;
    g_object_constructors["room_trigger"] = RoomTrigger::Construct;

    StateManager *sm = new StateManager(new Room("level1.json"));

    Rectangle mouse_rec = {0.f, 0.f, 16.f, 16.f};

    InitAudioDevice();
    Music day_music = LoadMusicStream("../music/day_theme.wav");
    Music dream_music = LoadMusicStream("../music/dream_theme.wav");
    PlayMusicStream(day_music);

    while(!WindowShouldClose()) {
        //
        mouse_rec.x = (float)GetMouseX() / 3.f;
        mouse_rec.y = (float)GetMouseY() / 3.f;
        sm->Update();

        UpdateMusicStream(day_music);

        BeginTextureMode(render);
        ClearBackground(BLACK);
        DrawTexturePro(background_lg, {0, 0, 80, 45},
                       {0, 0, 320, 180},
                       {0, 0}, 0, WHITE);
        sm->Draw();
        //
        /*if(((Room *)sm->GetState())->CheckCollisionsTiles(mouse_rec, 1, "collision")) {
            DrawRectangleRec(mouse_rec, RED);
        }
        else {
            DrawRectangleRec(mouse_rec, BLUE);
        }*/
        EndTextureMode();

        BeginDrawing();
        DrawTexturePro(render.texture, {0, 0, 320, -180}, {0, 0, 960, 540}, {0, 0}, 0, WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    delete sm;
    UnloadTexture(tileset_texture);
    UnloadRenderTexture(render);
    UnloadMusicStream(day_music);
    UnloadMusicStream(dream_music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
