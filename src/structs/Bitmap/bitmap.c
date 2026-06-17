#include "bitmap.h"
#include <stdlib.h>

Bitmap * createEmptyBitmap(uint w, uint h){
    Bitmap * bitmap = malloc(sizeof(Bitmap));
    if(!bitmap) return NULL;

    bitmap->bmp = malloc(w * sizeof(SDL_Color *));
    if(!bitmap->bmp){
        free(bitmap);
        return NULL;
    }

    for(int i = 0; i < w; ++i){
        bitmap->bmp[i] = malloc(h*sizeof(SDL_Color));
        if(!bitmap->bmp[i]){
            for(int j = 0; j < i; ++j){
                free(bitmap->bmp[j]);
            }
            free(bitmap->bmp);
            free(bitmap);
            return NULL;
        }

        for(int j = 0; j < h; ++j){
            SDL_Color empty;
            empty.r = 255;
            empty.g = 255;
            empty.b = 255;
            empty.a = 0;
            bitmap->bmp[i][j] = empty;
        }
    }

    bitmap->h = h;
    bitmap->w = w;

    return bitmap;
}


Bitmap * duplicateBitmap(Bitmap * bitmap){
    if(!bitmap) return NULL;

    Bitmap * newBmp = createEmptyBitmap(bitmap->w, bitmap->h);
    if(!newBmp) return NULL;

    for(int i = 0; i < bitmap->w; ++i){
        for(int j = 0; j < bitmap->h; ++j){
            newBmp->bmp[i][j] = bitmap->bmp[i][j];
        }
    }

    return newBmp;
}

void destroyBitmap(Bitmap * bitmap){
    if(!bitmap) return;

    for(int i = 0; i < bitmap->w; ++i){
        free(bitmap->bmp[i]);
    }

    free(bitmap->bmp);
    free(bitmap);
}
