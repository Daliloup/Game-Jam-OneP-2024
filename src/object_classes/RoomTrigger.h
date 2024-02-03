#ifndef CHOUETTE_ROOMTRIGGER_H
#define CHOUETTE_ROOMTRIGGER_H

#include "../Object.h"

#include <nlohmann/json_fwd.hpp>

class RoomTrigger : public Object {
public:
    explicit RoomTrigger(nlohmann::json json_object);

    void Update() override;

    static Object *Construct(nlohmann::json json_object);

private:
    std::string m_target_room;
    int m_target_x, m_target_y;
};


#endif //CHOUETTE_ROOMTRIGGER_H
