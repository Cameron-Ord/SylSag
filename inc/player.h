#ifndef PLAYER_H
#define PLAYER_H
#include "player_structs.h"
void initialize_player(struct Player_Class* player, Player_States* player_states,
                       PLAYER_METADATA* meta);
void do_player_events(struct Player_Class* player);
#endif
