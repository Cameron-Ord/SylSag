#ifndef INPUTS_H
#define INPUTS_H
#include "struct_inputs.h"
void poll_events(struct Inputs* i, struct SDL_CLASS* sc);
void set_window_resized(int* w, int* h, SDL_Window* window);
#endif
