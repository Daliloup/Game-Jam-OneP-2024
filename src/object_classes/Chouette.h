//
// Created by sanch on 03/02/2024.
//

#ifndef CHOUETTE_CHOUETTE_H
#define CHOUETTE_CHOUETTE_H
#include "../Object.h"


class Chouette:public Object{
public:
    Chouette(Vector2 position, Texture *tex);
    void Update() override;
    void Draw() override;
private:
    Texture *texture;
};


#endif //CHOUETTE_CHOUETTE_H