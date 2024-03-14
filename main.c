#include "inc/main.h"

int main(int argc, char* argv[]) {
  int              err;
  struct SDL_CLASS sdl_class;
  Renderer         rend;
  Window           win;
  Player_Class     player;
  Inputs           inputs;
  SDL_Audio        audio;
  err = init_sdl2();
  if (err < 0) {
    return 1;
  }
  err = create_contexts(&rend, &win);
  if (err < 0) {
    return 1;
  }
  err = create_audio_device(&audio);
  if (err < 0) {
    return 1;
  }
  assign_allocated_ptrs(&sdl_class, win, rend, audio, inputs);

  while (sdl_class.running) {
  }

  return 0;
}

int init_sdl2() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    const char* err = SDL_GetError();
    SDL_Log("SDL ERR : %s", err);
    return -1;
  }
  return 0;
}

int create_contexts(Renderer* rend, Window* win) {
  int err;
  rend->r = NULL;
  win->w  = NULL;
  err     = create_window(win);
  if (err < 0) {
    return err;
  }
  err = create_renderer(rend->r, win->w);
  if (err < 0) {
    return err;
  }
  return 0;
}
int create_window(Window* win) {
  win->w = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win->width,
                            win->height, 0);
  if (!win->w) {
    const char* err = SDL_GetError();
    SDL_Log("ERROR CREATING WINDOW : %s", err);
    return -1;
  }
  return 0;
}

int create_renderer(SDL_Renderer* rend, SDL_Window* win) {
  rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!rend) {
    const char* err = SDL_GetError();
    SDL_Log("ERROR CREATING RENDERER : %s", err);
    return -1;
  }
  return 0;
}

int create_audio_device(SDL_Audio* audio) {
  audio->spec.freq     = SR;
  audio->spec.format   = AUDIO_S16;
  audio->spec.channels = 2;
  audio->spec.samples  = BL;
  audio->spec.callback = audio_cb;
  audio->audio_state   = 1;
  audio->dev           = SDL_OpenAudioDevice(NULL, 0, &audio->spec, NULL, 0);
  if (!audio->dev) {
    const char* err = SDL_GetError();
    printf("ERROR OPENING DEVICE : %s\n", err);
    return -1;
  }
  SDL_PauseAudioDevice(audio->dev, audio->audio_state);
  return 0;
}

void assign_allocated_ptrs(struct SDL_CLASS* sdl_class, Window w, Renderer r, SDL_Audio aud,
                           Inputs inputs) {
  *sdl_class->km    = inputs;
  *sdl_class->win   = w;
  *sdl_class->ren   = r;
  *sdl_class->audio = aud;
}
