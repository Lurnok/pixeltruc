#ifndef PROJECT_H
#define PROJECT_H

#include "../Layer/layer.h"
#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"

struct _Project{
    char * name;
    char * save_path;
    uint h;
    uint w;
    Layers * layers;
};

struct _Layers{
    Layer ** layers;
    uint capacity;
    uint size;
};

Project * createProject(char * name, char * save_path, uint h, uint w);
void deleteProject(Project * project);

Layers * createLayers(uint capacity);
void deleteLayers(Layers * layers);

#endif