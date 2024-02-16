#include <iostream>
#include "raylib.h"

#include "ObjectManager.h"
#include "Object.h"
#include "Room/Room.h"
#include "Tileset.h"
#include "object_classes/Bell.h"
#include "object_classes/Button.h"
#include "object_classes/Chouette.h"
#include "object_classes/Door.h"
#include "object_classes/RoomTrigger.h"
#include "object_classes/Fox.h"
#include "StateManager.h"
#include "GameOver.h"

#include <unordered_map>
#include <string>

std::unordered_map<std::string, Tileset *> g_tilesets;
std::unordered_map<std::string, Texture *> g_textures;
std::unordered_map<std::string, ObjectConstructor> g_object_constructors;
std::unordered_map<std::string, int> g_values;


int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(960, 540, "window");
    SetTargetFPS(60);

    RenderTexture render = LoadRenderTexture(320, 180);

    g_textures["chouette"] = new Texture(LoadTexture("./sprites/chouette.png"));
    g_textures["door_tile"] = new Texture(LoadTexture("./sprites/door_tile.png"));
    g_textures["button"] = new Texture (LoadTexture("./sprites/button.png"));
    g_textures["bell"] = new Texture(LoadTexture("./sprites/bell.png"));
    g_textures["background_normal"] = new Texture(LoadTexture("./sprites/background_lg.png"));


    g_tilesets["chouette_sleeping"] = new Tileset(
            new Texture(LoadTexture("./sprites/chouette_sleeping_sheet.png")),
            32, 32, true);

    g_tilesets["chouette"] = new Tileset(
            new Texture(LoadTexture("./sprites/chouette_sheet.png")),
            32, 32, true
            );

    g_tilesets["dream"] = new Tileset(
            new Texture(LoadTexture("./sprites/tileset.png")),
            8, 8, true
            );

    g_tilesets["fox"] = new Tileset(
            new Texture(LoadTexture("./sprites/fox_sheet.png")),
            32, 18, true
            );

    g_object_constructors["chouette"] = Chouette::Construct;
    g_object_constructors["room_trigger"] = RoomTrigger::Construct;
    g_object_constructors["door"] = Door::Construct;
    g_object_constructors["button"] = Button::Construct;
    g_object_constructors["bell"] = Bell::Construct;
    g_object_constructors["fox"] = Fox::Construct;

    StateManager *sm = new StateManager(new Room("level1.json"));

    Rectangle mouse_rec = {0.f, 0.f, 16.f, 16.f};

    InitAudioDevice();
    Music day_music = LoadMusicStream("./music/dream_theme.wav");        //actually dream music
    Music dream_music = LoadMusicStream("./music/day_theme.wav");        //actually day music
    Music *current_music = &day_music;
    PlayMusicStream(day_music);


    while(!WindowShouldClose()) {
        //
        mouse_rec.x = (float)GetMouseX() / 3.f;
        mouse_rec.y = (float)GetMouseY() / 3.f;
        sm->Update();

        if(sm->GetState()->ID() == 1) {     //room
            std::string room_name = ((Room *)sm->GetState())->FileName();
            if(room_name.find('N') != std::string::npos) {  //not in nightmare
                if(current_music == &dream_music) {
                    PauseMusicStream(*current_music);
                    float whence = GetMusicTimePlayed(*current_music);
                    current_music = &day_music;
                    PlayMusicStream(*current_music);
                    SeekMusicStream(*current_music, whence * (15.f/8.f));
                    printf("a\n");
                }
            }
            else {      //in nightmare
                if(current_music == &day_music) {
                    PauseMusicStream(*current_music);
                    float whence = GetMusicTimePlayed(*current_music);
                    current_music = &dream_music;
                    PlayMusicStream(*current_music);
                    SeekMusicStream(*current_music, whence * (8.f/15.f));
                    printf("b\n");
                }
            }
        }

        UpdateMusicStream(*current_music);

        BeginTextureMode(render);
        ClearBackground(BLACK);
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
        DrawTexturePro(render.texture, {0, 0, 320, -180}, {0, 0, (float)GetRenderWidth(), (float)GetRenderHeight()}, {0, 0}, 0, WHITE);
        DrawFPS(10, 10);
        DrawText("SPACE : jump", 10, 32, 20, WHITE);
        DrawText("D : sleep", 10, 54, 20, WHITE);
        EndDrawing();
    }

    delete sm;

    for(auto a : g_textures) {
        if(a.second == nullptr) continue;
        UnloadTexture(*a.second);
        delete a.second;
    }
    g_textures.clear();

    for(auto a : g_tilesets) delete a.second;
    g_tilesets.clear();

    UnloadRenderTexture(render);
    UnloadMusicStream(day_music);
    UnloadMusicStream(dream_music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
