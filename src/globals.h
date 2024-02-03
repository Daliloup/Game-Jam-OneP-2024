#ifndef GLOBALS_H
#define GLOBALS_H

#include <unordered_map>
#include <string>

#include "Object.h"

class Tileset;

extern std::unordered_map<std::string, Tileset *> g_tilesets;
extern std::unordered_map<std::string, Texture *> g_textures;
extern std::unordered_map<std::string, ObjectConstructor> g_object_constructors;

#endif
