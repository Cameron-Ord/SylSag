#ifndef STRUCT_MAIN_H
#define STRUCT_MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

typedef struct {
  SDL_AudioDeviceID dev;
  SDL_AudioSpec     spec;
  int               audio_state;
} SDL_Audio;

typedef struct {
  int pos_x;
  int pos_y;
} Player_Class;

typedef struct {
  SDL_Renderer*     r;
  SDL_RendererFlags r_flags;
} Renderer;

typedef struct {
  int             width;
  int             height;
  SDL_Window*     w;
  SDL_WindowFlags w_flags;
} Window;

struct SDL_CLASS {
  SDL_Audio*    audio;
  Player_Class* player;
  Window*       win;
  Renderer*     ren;
  SDL_errorcode sdl_err;
  int           running;
};

#endif
