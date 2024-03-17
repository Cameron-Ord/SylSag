#include "inc/render.h"
#include <SDL2/SDL_image.h>
void clear_render(SDL_Renderer* r) {
  SDL_RenderClear(r);
  SDL_SetRenderDrawColor(r, 40, 42, 54, 0);
}

void render_player(SDL_Renderer* r, struct Player_Class player) {
  SDL_RenderClear(r);
  SDL_RenderCopy(r, player.meta->tex, NULL, &player.meta->dst);
}

void present_render(SDL_Renderer* r) { SDL_RenderPresent(r); }

void create_player_sprite(SDL_Renderer* r, struct Player_Class* player) {
  player->meta->surf = IMG_Load("TEST.png");
  player->meta->tex  = SDL_CreateTextureFromSurface(r, player->meta->surf);
  SDL_FreeSurface(player->meta->surf);
  player->meta->dst.x = 100;
  player->meta->dst.y = 100;
  player->meta->dst.w = 32;
  player->meta->dst.h = 32;
}
