#include "inc/movement.h"
#include <stdio.h>
#include <stdlib.h>
void move(int move_amount, int* dst_x) { *dst_x += move_amount; }
int* ascend(int jump_str, int j_max, int* dst_y) {
  static int asc_tracker = 0;
  *dst_y += -jump_str;
  asc_tracker += jump_str;
  /*
   * Returning the pointer to the static variable, so that I can check the amount in the function
   * that calls this one, so that I don't need to pass the whole player struct. Pretty handy that it
   * doesnt go out of scope since it's static.
   */
  return &asc_tracker;
}
/*The idea here is that I will send the pos_y of the platform the player is standing over and use
 * that as the landing spot. Not sure how exactly to do this, but i'm sure i'll find out
 */
int descend(int gravity, int platform_y, int* dst_y) {
  if (*dst_y < platform_y) {
    *dst_y += gravity;
    /*Keep falling*/
    return 0;
  } else {
    /*Terminates the jump*/
    return -1;
  }
}
