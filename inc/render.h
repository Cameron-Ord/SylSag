#ifndef RENDER_H
#define RENDER_H
#include "player_structs.h"
#include "struct_main.h"
void clear_render(SDL_Renderer* r);
void create_player_sprite(SDL_Renderer* r, struct Player_Class* player);
void render_player(SDL_Renderer* r, struct Player_Class player);
void present_render(SDL_Renderer* r);
#endif
