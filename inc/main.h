#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL_audio.h>
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

#include <SDL2/SDL.h>

typedef enum { LEFT, RIGHT, UP, DOWN, JUMP_ACTION } Keys;

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

typedef struct {
  Keys keys;
  void (*key_action)();
} Inputs;

struct SDL_CLASS {
  SDL_Audio*    audio;
  Inputs*       km;
  Window*       win;
  Renderer*     ren;
  SDL_errorcode sdl_err;
  int           running;
};

int  create_contexts(Renderer* rend, Window* win);
int  init_sdl2();
int  create_renderer(SDL_Renderer* r, SDL_Window* w);
int  create_window(Window* w);
int  create_audio_device(SDL_Audio* audio);
void assign_allocated_ptrs(struct SDL_CLASS* sdl_class, Window w, Renderer r, SDL_Audio aud,
                           Inputs inputs);
#endif
