#ifndef CHOUETTE_FOX_H
#define CHOUETTE_FOX_H

#include "../Object.h"

class Tileset;

class Fox : public Object {
public:
    Fox(nlohmann::json object_json);

    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json object_json);

private:
    void HandleHorizontalCollisions();
    void HandleVerticalCollisions();

    Tileset *m_tileset;
    int m_anim_state;
};


#endif //CHOUETTE_FOX_H
