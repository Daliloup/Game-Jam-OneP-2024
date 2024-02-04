#ifndef CHOUETTE_SLEEPINGCHOUETTE_H
#define CHOUETTE_SLEEPINGCHOUETTE_H

#include "../Object.h"

class Tileset;

//Used to come back to the real world
class SleepingChouette : public Object {
public:
    SleepingChouette(Vector2 position);

    void Update() override;
    void Draw() override;
private:
    Tileset *m_tileset;
    int m_anim_state;
};


#endif //CHOUETTE_SLEEPINGCHOUETTE_H
