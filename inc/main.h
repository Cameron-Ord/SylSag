#ifndef MAIN_H
#define MAIN_H
#include "struct_main.h"
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x, y) ((x) < 0 ? -(x) : (x))
#define SWAP(x, y)                                                                                 \
  do {                                                                                             \
    typeof(x) temp = x;                                                                            \
    x              = y;                                                                            \
    y              = temp;                                                                         \
  } while (0)
#define LENGTH(x) (sizeof(x) / sizeof((x)[0]))
#define SR 44100
#define BL 256
void audio_cb(void* userdata, Uint8* stream, int bytes);
int  create_contexts(Renderer* rend, Window* win);
int  init_sdl2();
int  create_renderer(SDL_Renderer** r, SDL_Window** w);
int  create_window(Window** w);
int  create_audio_device(SDL_Audio* audio);
void assign_allocated_ptrs(struct SDL_CLASS* sdl_class, Window w, Renderer r, SDL_Audio aud);
#endif
