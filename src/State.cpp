#include "State.h"

State::State() {
    m_manager = nullptr;
}

State::~State() = default;
void State::Update() { }
void State::Draw() { }
StateManager *State::Manager() { return m_manager; }
void State::SetManager(StateManager *manager) { m_manager = manager; }


