#ifndef GLOBALS_H
#define GLOBALS_H

#include <unordered_map>
#include <string>

class Tileset;
extern std::unordered_map<std::string, Tileset *> g_tilesets;

#endif
