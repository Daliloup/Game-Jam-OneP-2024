//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_CHOUETTE_H
#define CHOUETTE_CHOUETTE_H
#include "../Object.h"


class Chouette : public Object{
public:
    Chouette(Vector2 position);
    Chouette(nlohmann::json json_obect);
    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json json_obect);

private:
    Texture *texture;
    void HandleVerticalCollisions();
    void HandlsHorizontalCollisions();
};


#endif //CHOUETTE_CHOUETTE_H
