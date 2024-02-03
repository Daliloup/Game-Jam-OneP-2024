cmake_minimum_required(VERSION 3.27)
project(Chouette)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)
add_subdirectory(json)
file(COPY ./sprites DESTINATION .)

add_executable(Chouette main.cpp
        Tileset.h
        Tileset.cpp
        Room/Room.h
        Room/Room.cpp
        Room/Layer.h
        Room/Layer.cpp
        Room/TileLayer.h
        Room/TileLayer.cpp
        globals.h
        ObjectManager.cpp
        ObjectManager.h
        Object.cpp
        Object.h
        object_classes/Chouette.cpp
        object_classes/Chouette.h
)
target_link_libraries(Chouette PRIVATE raylib)
target_include_directories(Chouette PRIVATE json/single_include)
