#include "layer.h"
#include "../Bitmap/bitmap.h"
#include <stdlib.h>

Layer * createEmptyLayer(uint w, uint h){
    Bitmap * bmp = createEmptyBitmap(w, h);
    if(!bmp) return NULL;

    Layer * layer = malloc(sizeof(Layer));
    if(!layer){
        destroyBitmap(bmp);
        return NULL;
    };

    layer->pixels = bmp;
    layer->alpha = 255;
    layer->z_index = 0;

    return layer;
}

Layer * duplicateLayer(Layer * layer){
    if(!layer) return NULL;

    Layer * newLayer = createEmptyLayer(layer->pixels->w, layer->pixels->h);
    if(!newLayer) return NULL; 

    Bitmap * bmpcpy = duplicateBitmap(layer->pixels);
    if(!bmpcpy){
        destroyLayer(newLayer);
        return NULL;
    }

    newLayer->pixels = bmpcpy;
    newLayer->alpha = 255;
    newLayer->z_index = layer->z_index + 1;

    return newLayer;
}

void destroyLayer(Layer * layer){
    if(!layer) return;
    destroyBitmap(layer->pixels);
    free(layer);
}
