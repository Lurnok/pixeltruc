#ifndef ENGINE_H
#define ENGINE_H


#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

struct _Engine{
    SDL_Window * window;
    SDL_Renderer * renderer;
    struct nk_context * nk_ctx;
};

Engine * createEngine(void);
void destroyEngine(Engine * engine);

#endif