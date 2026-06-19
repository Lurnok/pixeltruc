#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H


#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"
#include <SDL2/SDL_keycode.h>

void handle_input(App * app);

void main_menu_input(App * app, SDL_KeyCode key);
void project_input(App * app, SDL_KeyCode key);

#endif