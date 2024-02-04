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
}

Room::~Room() {
    for(Layer *l : m_layers) delete l;
}

void Room::Update() {
    for(Layer *l : m_layers) l->Update();
}

void Room::Draw() {
    if(m_bg != nullptr)
    DrawTexturePro(*m_bg, {0, 0, 80, 45},
                   {0, 0, 320, 180},
                   {0, 0}, 0, WHITE);
    for(Layer *l : m_layers) l->Draw();
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
