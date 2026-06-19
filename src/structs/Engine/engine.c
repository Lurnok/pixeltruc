// clang-format off
#include "../../functions/nuklear/nuklear_config.h"
#include "../../../external/Nuklear/nuklear.h"
#include "../../../external/Nuklear/demo/sdl_renderer/nuklear_sdl_renderer.h"
// clang-format on

#include "engine.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>

Engine * createEngine(void){
    Engine * engine = malloc(sizeof(Engine));
    if(!engine) return NULL;

    engine->window = SDL_CreateWindow("Pixeltruc", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if(!engine->window){
        free(engine);
        return NULL;
    }

    engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);
    if(!engine->renderer){
        SDL_DestroyWindow(engine->window);
        free(engine);
    }

    engine->nk_ctx = nk_sdl_init(engine->window, engine->renderer);
    if(!engine->nk_ctx){
        SDL_DestroyRenderer(engine->renderer);
        SDL_DestroyWindow(engine->window);
        free(engine);
    }

    float font_scale = 1.0f;
    struct nk_font_atlas *atlas;
    struct nk_font       *font;
    nk_sdl_font_stash_begin(&atlas);
    font = nk_font_atlas_add_default(atlas, 13 * font_scale, NULL);
    nk_sdl_font_stash_end();
    nk_style_set_font(engine->nk_ctx, &font->handle);


    return engine;
}

void destroyEngine(Engine * engine){
    if(!engine) return;
    nk_free(engine->nk_ctx);
    SDL_DestroyRenderer(engine->renderer);
    SDL_DestroyWindow(engine->window);
    free(engine);
}
