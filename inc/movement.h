#ifndef MOVEMENT_H
#define MOVEMENT_H
void move(int move_amount, int* dst_x);

int* ascend(int jump_str, int j_max, int* dst_y);
int  descend(int gravity, int platform_y, int* dst_y);
#endif
