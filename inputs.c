#include "inc/inputs.h"
#include "inc/movement.h"

void poll_events(struct Inputs* in, struct SDL_CLASS* sc, struct Player_Class* player) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_KEYDOWN: {
      switch (in->keys) {
      case JUMP_ACTION: {
        player->player_states->is_jumping = 1;
        break;
      }
      case LEFT: {
        player->move_direction           = -player->move_rate;
        player->player_states->is_moving = 1;
        break;
      }
      case RIGHT: {
        player->move_direction           = player->move_rate;
        player->player_states->is_moving = 1;
        break;
      }
      case UP: {
        /*implement look up*/
        break;
      }
      case DOWN: {
        /*implement look down*/
        break;
      }
      }
      break;
    }
    case SDL_KEYUP: {
      switch (in->keys) {
      case JUMP_ACTION: {
        break;
      }
      case LEFT: {
        player->player_states->is_moving = 0;
        break;
      }
      case RIGHT: {
        player->player_states->is_moving = 0;
        break;
      }
      case UP: {
        /*implement look up*/
        break;
      }
      case DOWN: {
        /*implement look down*/
        break;
      }
      }
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
