//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_GAMEOVER_H
#define CHOUETTE_GAMEOVER_H
#include "State.h"


class GameOver : public State {
public:
    GameOver();
    ~GameOver() override;

    void Update() override;
    void Draw() override;
private:

};


#endif //CHOUETTE_GAMEOVER_H
