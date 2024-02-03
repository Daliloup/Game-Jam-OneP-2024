#ifndef CHOUETTE_STATEMANAGER_H
#define CHOUETTE_STATEMANAGER_H

#include <vector>

class State;

class StateManager {
public:
    StateManager(State *state = nullptr);
    ~StateManager();

    void Update();
    void Draw();

    void SetState(State *state);
    State *GetState();

private:
    void EmptyTrashCan();

    State *m_state;
    std::vector<State *> m_trashcan;
};


#endif //CHOUETTE_STATEMANAGER_H
