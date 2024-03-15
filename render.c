#include "inc/render.h"
#include "inc/main.h"
#include <SDL2/SDL_error.h>

void do_render(SDL_Renderer* r, SDL_Window* w) {
  SDL_RenderClear(r);
  SDL_SetRenderDrawColor(r, 40, 42, 54, 0);
  SDL_RenderPresent(r);
}
