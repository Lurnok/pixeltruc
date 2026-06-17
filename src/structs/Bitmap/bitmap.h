#ifndef BITMAP_H
#define BITMAP_H

#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_stdinc.h>

struct _Bitmap{
    SDL_Color ** bmp;
    uint w;
    uint h;
};

Bitmap * createEmptyBitmap(uint w, uint h);
Bitmap * duplicateBitmap(Bitmap * bitmap);
void destroyBitmap(Bitmap * bitmap); 

#endif