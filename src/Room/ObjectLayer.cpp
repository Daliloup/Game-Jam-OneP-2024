#include "ObjectLayer.h"

#include "../globals.h"
#include "../ObjectManager.h"

#include <nlohmann/json.hpp>

ObjectLayer::ObjectLayer(nlohmann::json layer_json) : Layer(layer_json) {
    m_type = LayerType::LayerType_Objects;

    m_object_manager = new ObjectManager;
    m_object_manager->SetLayer(this);

    for(auto entity_json : layer_json["entities"]) {
        std::string entity_name = entity_json["name"];
        if(g_object_constructors.count(entity_name) == 0) {
            printf("Unknown object name : %s\n", entity_name.c_str());
            continue;
        }
        printf("Spawining object %s\n", entity_name.c_str());
        m_object_manager->AddObject(g_object_constructors[entity_name](entity_json));
    }
}

ObjectLayer::~ObjectLayer() {
    delete m_object_manager;
}

void ObjectLayer::Update() {
    m_object_manager->Update();
}

void ObjectLayer::Draw() {
    m_object_manager->Draw();
}
