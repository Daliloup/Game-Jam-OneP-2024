#include "Room.h"

#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include "../globals.h"
#include "Layer.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

Room::Room(const char *filename) : State() {
    m_filename = filename;
    m_width = 0; m_height = 0;
    printf("Room::Room : loading %s\n", filename);

    std::ifstream level_file(std::string("./levels/") + filename);
    json level_json = json::parse(level_file);
    level_file.close();

    if(!level_json.contains("ogmoVersion")) {
        printf("Failed to parse %s\n", filename);
        return;
    }

    for(const auto& json_layer : level_json["layers"]) {
        Layer *l = nullptr;
        if(json_layer.contains("data")) {
            l = new TileLayer(json_layer);
        }
        else if(json_layer.contains("entities")) {
            l = new ObjectLayer(json_layer);
        }
        else {
            l = new Layer(json_layer);
        }
        l->SetRoom(this);
        m_layers.push_back(l);
    }

    if(m_filename[m_filename.size()-6] == 'N') {
        //TODO : load nighmare bg
        m_bg = nullptr;
    }
    else {
        m_bg = g_textures["background_normal"];
    }

    m_camera = {
            {0.f, 0.f},
            {0.f, 0.f},
            0.f, 1.f
    };
    m_following_object = nullptr;

    m_width = level_json["width"];
    m_height = level_json["height"];
}

Room::~Room() {
    for(Layer *l : m_layers) delete l;
}

void Room::Update() {
    for(Layer *l : m_layers) l->Update();

    if(m_following_object != nullptr) {
        Rectangle objhb = m_following_object->GetHitbox();
        m_camera.target.x = (float)(int)objhb.x + objhb.width/2.f - 320.f/2.f;
        m_camera.target.y = (float)(int)objhb.y + objhb.height/2.f - 180.f/2.f;
    }

    if(m_camera.target.x < 0) m_camera.target.x = 0.f;
    else if(m_camera.target.x + 320.f >= (float)m_width) m_camera.target.x = (float)m_width-320.f;

    if(m_camera.target.y < 0) m_camera.target.y = 0.f;
    else if(m_camera.target.y + 180.f >= (float)m_height) m_camera.target.y = (float)m_height-180.f;
}

void Room::Draw() {
    if(m_bg != nullptr)
    DrawTexturePro(*m_bg, {0, 0, 80, 45},
                   {0, 0, 320, 180},
                   {0, 0}, 0, WHITE);
    BeginMode2D(m_camera);
    for(Layer *l : m_layers) l->Draw();
    EndMode2D();
}

bool Room::CheckCollisionsTiles(Rectangle rec, short tile_to_check, std::string layer_name) {
    for(Layer *l : m_layers) {
        if(l->Type() != LayerType_Tiles || l->Name() != layer_name) continue;
        if(((TileLayer *)l)->CheckCollision(rec, tile_to_check)) return true;
    }
    return false;
}

Layer *Room::GetLayer(std::string layer_name) {
    for(Layer *l : m_layers) {
        if(l->Name() == layer_name) return l;
    }
    return nullptr;
}

std::string Room::FileName() {
    return m_filename;
}

Object *Room::GetFollowingObject() {
    return m_following_object;
}

void Room::SetFollowingObject(Object *obj) {
    m_following_object = obj;
}


