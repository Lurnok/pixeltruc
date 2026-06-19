#include "SDL_gui.h"
#include <SDL2/SDL_render.h>
#include "../../../structs/App/app.h"

void SDL_draw(App *app){
    SDL_SetRenderDrawColor(app->engine->renderer, 255, 255, 255, 255);
    SDL_RenderClear(app->engine->renderer);
    SDL_RenderPresent(app->engine->renderer);
}