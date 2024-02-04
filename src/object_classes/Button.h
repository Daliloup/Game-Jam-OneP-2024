
#ifndef CHOUETTE_BUTTON_H
#define CHOUETTE_BUTTON_H

#include "../Object.h"

class Button : public Object {
public:
    explicit Button(nlohmann::json object_json);

    void Update() override;
    void Draw() override;

    static Object *Construct(nlohmann::json object_json);

private:
    std::string m_key;
    Texture *m_texture;
};


#endif //CHOUETTE_BUTTON_H
