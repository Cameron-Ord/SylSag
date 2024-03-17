#include "inc/movement.h"
#include "inc/player.h"

/*This kinda sucks but it's just to get somewhere while I build the rest*/

void do_player_events(struct Player_Class* player) {
  if (player->player_states->is_moving) {
    move(player->move_direction, &player->meta->dst.x);
  }
  if (player->player_states->is_jumping && !player->player_states->is_falling) {
    int* t = ascend(player->jump_strength, player->jump_max, &player->meta->dst.y);
    if (*t >= 20) {
      player->player_states->is_falling = 1;
      *t                                = 0;
    }
  } else if (player->player_states->is_jumping && player->player_states->is_falling) {
    int t = descend(2, player->pos_y, &player->meta->dst.y);
    if (t < 0) {
      player->player_states->is_falling = 0;
      player->player_states->is_jumping = 0;
    }
  }
}
