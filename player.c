#include "inc/player.h"

void initialize_player(struct Player_Class* player, Player_States* player_states,
                       PLAYER_METADATA* player_meta) {
  player_states->is_jumping       = 0;
  player_states->is_moving        = 0;
  player_states->is_running       = 0;
  player_states->is_attacking     = 0;
  player_states->receiving_damage = 0;
  player->level                   = 0;
  player->health                  = 100;
  player->move_rate               = 2;
  player->jump_strength           = 1;
  player->attack_damage           = 5;
  player->pos_x                   = 50;
  player->pos_y                   = 50;
  player->player_states           = player_states;
  player->meta                    = player_meta;
}
