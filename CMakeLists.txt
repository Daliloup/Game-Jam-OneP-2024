cmake_minimum_required(VERSION 3.27)
project(Chouette)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)
add_subdirectory(json)
file(COPY ./sprites DESTINATION .)
file(COPY ./levels DESTINATION .)
file(COPY ./music DESTINATION .)

add_executable(Chouette src/main.cpp
        src/Tileset.h
        src/Tileset.cpp
        src/Room/Room.h
        src/Room/Room.cpp
        src/Room/Layer.h
        src/Room/Layer.cpp
        src/Room/TileLayer.h
        src/Room/TileLayer.cpp
        src/globals.h
        src/ObjectManager.cpp
        src/ObjectManager.h
        src/Object.cpp
        src/Object.h
        src/object_classes/Chouette.cpp
        src/object_classes/Chouette.h
        src/Room/ObjectLayer.h
        src/Room/ObjectLayer.cpp
        src/StateManager.h
        src/State.h
        src/State.cpp
        src/StateManager.cpp
        src/object_classes/RoomTrigger.h
        src/object_classes/RoomTrigger.cpp
        src/GameOver.cpp
        src/GameOver.h
        src/MusicManager.cpp
        src/MusicManager.h
        src/object_classes/SleepingChouette.h
        src/object_classes/SleepingChouette.cpp
        src/object_classes/Door.h
        src/object_classes/Door.cpp
        src/object_classes/Button.h
        src/object_classes/Button.cpp
        src/object_classes/Bell.h
        src/object_classes/Bell.cpp
        src/object_classes/Fox.h
        src/object_classes/Fox.cpp
)
target_link_libraries(Chouette PRIVATE raylib)
target_include_directories(Chouette PRIVATE json/single_include)
