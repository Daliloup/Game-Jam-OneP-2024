#ifndef CHOUETTE_DOOR_H
#define CHOUETTE_DOOR_H

#include "../Object.h"

#include <nlohmann/json_fwd.hpp>

class Door : public Object {
public:
    explicit Door(nlohmann::json json_obect);

    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json json_obect);

private:
    std::string m_key;
    Texture *m_texture;
    bool m_open;
};


#endif //CHOUETTE_DOOR_H
