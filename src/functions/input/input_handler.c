#include "input_handler.h"

#include "../../../external/Nuklear/nuklear.h"
#include "../../../external/Nuklear/demo/sdl_renderer/nuklear_sdl_renderer.h"

#include "../../structs/App/app.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>

void handle_input(App * app){
    SDL_Event event;
    nk_input_begin(app->engine->nk_ctx);
        while (SDL_PollEvent(&event)) {
            nk_sdl_handle_event(&event);
            switch (event.type) {
                case SDL_QUIT:
                    app->state = QUIT;
                    break;
                case SDL_KEYDOWN:
                    switch (app->state) {
                        case MAINMENU:
                            main_menu_input(app, event.key.keysym.sym);
                            break;
                        case PROJECT:
                            project_input(app, event.key.keysym.sym);
                            break;
                        case QUIT:
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        nk_input_end(app->engine->nk_ctx);
}

void main_menu_input(App * app, SDL_KeyCode key){
    return;
}

void project_input(App * app, SDL_KeyCode key){
    return;
}