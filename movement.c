#include "inc/movement.h"
#include <stdio.h>
#include <stdlib.h>
void move(int move_amount, int* dst_x) {
  *dst_x += move_amount;
  printf("MOVE AMOUNT : %d\n", move_amount);
}

void jump(int jump_strength) {}
