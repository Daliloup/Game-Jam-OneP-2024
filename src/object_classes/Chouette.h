//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_CHOUETTE_H
#define CHOUETTE_CHOUETTE_H
#include "../Object.h"

class Tileset;

class Chouette : public Object{
public:
    Chouette(Vector2 position, bool enable_multijump = false);
    Chouette(nlohmann::json json_obect);
    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json json_obect);

    void SetCheckpointPosition(Vector2 pos);

    void GetRekt();
    bool Collide();

private:
    Tileset *m_tileset;
    float m_jump_power;
    bool m_enable_multijump;

    bool m_walking;
    bool m_go_right;
    int m_anim_state;
    int m_sprite_index;

    Vector2 m_checkpoint_position;

    void HandleVerticalCollisions();
    void HandleHorizontalCollisions();
    void HandleJump();
    void HandleSleep();

    bool Grounded();
};


#endif //CHOUETTE_CHOUETTE_H
