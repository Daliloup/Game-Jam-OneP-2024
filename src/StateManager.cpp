#include "StateManager.h"

#include "State.h"

StateManager::StateManager(State *state) {
    m_state = state;
}

StateManager::~StateManager() {
    delete m_state;
    m_state = nullptr;
}

void StateManager::Update() {
    if(m_state) m_state->Update();
    EmptyTrashCan();
}

void StateManager::Draw() {
    if(m_state) m_state->Draw();
}

void StateManager::SetState(State *state) {
    m_trashcan.push_back(m_state);
    m_state = state;
}

State *StateManager::GetState() {
    return m_state;
}

void StateManager::EmptyTrashCan() {
    for(State *s : m_trashcan) delete s;
    m_trashcan.clear();
}
