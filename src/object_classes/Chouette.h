//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_CHOUETTE_H
#define CHOUETTE_CHOUETTE_H
#include "../Object.h"


class Chouette : public Object{
public:
    Chouette(Vector2 position, bool enable_multijump = false);
    Chouette(nlohmann::json json_obect);
    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json json_obect);

private:
    Texture *m_texture;
    float m_jump_power;
    bool m_enable_multijump;

    void HandleVerticalCollisions();
    void HandleHorizontalCollisions();
    void HandleJump();
    void HandleSleep();

    bool Grounded();
};


#endif //CHOUETTE_CHOUETTE_H
