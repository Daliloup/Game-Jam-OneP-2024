#include "Room.h"

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Layer.h"
#include "TileLayer.h"

Room::Room(const char *filename) {
    printf("Room::Room : loading %s\n", filename);

    std::ifstream level_file(filename);
    json level_json = json::parse(level_file);
    level_file.close();

    if(!level_json.contains("ogmoVersion")) {
        printf("Failed to parse %s\n", filename);
        return;
    }

    for(auto json_layer : level_json["layers"]) {
        if(json_layer.contains("data")) {
            m_layers.push_back(new TileLayer(json_layer));
        }
        else if(json_layer.contains("entities")) {
            //entity layer
        }
        else {
            m_layers.push_back(new Layer(json_layer));
        }
    }
}

Room::~Room() {
    for(Layer *l : m_layers) delete l;
}

void Room::Update() {
    for(Layer *l : m_layers) l->Update();
}

void Room::Draw() {
    for(Layer *l : m_layers) l->Draw();
}