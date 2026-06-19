#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions/gui/gui.h"
#include "functions/input/input_handler.h"
#include "static/constants/app_state.h"
#include "static/constants/types.h"
#include "structs/App/app.h"

#include "../external/Nuklear/nuklear.h"
#include "../external/Nuklear/demo/sdl_renderer/nuklear_sdl_renderer.h"

int main(void){

    if(SDL_Init(SDL_INIT_EVERYTHING)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur lors de l'initialisation : %s", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);

    App * app = initApp();
    if(!app) exit(-1);

    while (app->state != QUIT) {
        handle_input(app);
        draw(app);
    }
    
    destroyApp(app);

    SDL_Quit();
    return 0;
}
