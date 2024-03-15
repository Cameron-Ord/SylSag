#include "inc/inputs.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

void poll_events(struct Inputs* in, struct SDL_CLASS* sc) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_KEYDOWN: {
      break;
    }
    case SDL_KEYUP: {
      break;
    }
    case SDL_WINDOWEVENT: {
      switch (e.window.event) {
      case SDL_WINDOWEVENT_SIZE_CHANGED: {
        set_window_resized(&sc->win->width, &sc->win->height, sc->win->w);
        break;
      }
      case SDL_WINDOWEVENT_RESIZED: {
        set_window_resized(&sc->win->width, &sc->win->height, sc->win->w);
        break;
      }
      }
      break;
    }
    case SDL_QUIT: {
      *in->running = 0;
      break;
    }
    default: {

      break;
    }
    }
  }
}

void set_window_resized(int* w, int* h, SDL_Window* window) { SDL_GetWindowSize(window, w, h); }
