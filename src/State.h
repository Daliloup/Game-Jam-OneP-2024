#ifndef CHOUETTE_STATE_H
#define CHOUETTE_STATE_H

class StateManager;

class State {
public:
    State();
    virtual ~State();
    virtual void Update();
    virtual void Draw();

    StateManager *Manager();
    void SetManager(StateManager *manager);

    int ID();

protected:
    int m_id;

private:
    StateManager *m_manager;
};


#endif //CHOUETTE_STATE_H
