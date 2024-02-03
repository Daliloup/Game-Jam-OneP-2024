//
// Created by sanch on 03/02/2024.
//

#include "GameOver.h"
#include "StateManager.h"
#include "Room/Room.h"

#include <raylib.h>

GameOver::GameOver() : State() {

}

GameOver::~GameOver() {

}

void GameOver::Update() {
    if(IsKeyPressed(KEY_SPACE)) {
        Manager()->SetState(new Room("level1.json"));
    }
}

void GameOver::Draw() {
    DrawText("Game over", 0, 0, 20, WHITE);
}
