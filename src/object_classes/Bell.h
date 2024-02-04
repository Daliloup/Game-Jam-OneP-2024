#ifndef CHOUETTE_BELL_H
#define CHOUETTE_BELL_H

#include "../Object.h"

class Bell : public Object {
public:
    Bell(nlohmann::json json_obect);

    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json json_object);

private:
    Texture *m_texture;
};


#endif //CHOUETTE_BELL_H
