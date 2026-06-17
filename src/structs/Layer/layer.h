#ifndef LAYER_H
#define LAYER_H

#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>

struct _Layer{
    Bitmap * pixels;
    Uint8 alpha;
    uint z_index;
};

Layer * createEmptyLayer(uint w, uint h);
Layer * duplicateLayer(Layer * layer);
void destroyLayer(Layer * layer);



#endif