#include "gui.h"
#include "SDL/SDL_gui.h"
#include "Nuklear/nuklear_gui.h"
#include "../../structs/App/app.h"

void draw(App * app){
    SDL_SetRenderDrawColor(app->engine->renderer, BG_LIGHTER_R, BG_LIGHTER_G, BG_LIGHTER_B, 255);
    SDL_RenderClear(app->engine->renderer);
    SDL_draw(app);
    nuklear_draw(app);

    SDL_RenderPresent(app->engine->renderer);
}