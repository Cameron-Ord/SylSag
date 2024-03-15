#ifndef PLAYER_STRUCTS_H
#define PLAYER_STRUCTS_H

#include "struct_main.h"

typedef struct {
  int is_jumping;
  int is_running;
  int is_attacking;
  int receiving_damage;
} Player_States;

struct Player_Class {
  int            move_rate;
  int            jump_strength;
  int            attack_damage;
  int            health;
  int            level;
  int            pos_x;
  int            pos_y;
  Player_States* player_states;
};

#endif
