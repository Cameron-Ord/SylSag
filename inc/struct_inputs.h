#ifndef STRUCT_INPUTS_H
#define STRUCT_INPUTS_H
#include "player_structs.h"
#include "struct_main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
typedef enum {
  LEFT        = SDLK_a,
  RIGHT       = SDLK_d,
  UP          = SDLK_w,
  DOWN        = SDLK_s,
  JUMP_ACTION = SDLK_SPACE
} Keys;

struct Inputs {
  Keys keys;
  int* running;
  int* held_keys;
  int* free_keys;
  void (*key_action)();
};

#endif
