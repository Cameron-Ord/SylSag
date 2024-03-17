#include "inc/movement.h"
#include "inc/player.h"

void do_player_events(struct Player_Class* player) {
  if (player->player_states->is_moving == 1) {
    move(player->move_direction, &player->meta->dst.x);
  }
}
