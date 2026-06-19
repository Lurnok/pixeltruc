#include "project.h"
#include <stdlib.h>
#include <string.h>

Project * createProject(char * name, char * save_path, uint h, uint w){
    Project * project = malloc(sizeof(Project));
    if(!project) return NULL;

    project->name = malloc((strlen(name) + 1) * sizeof(char));
    if(!project->name){
        free(project);
        return NULL;
    }
    strcpy(project->name, name);

    project->save_path = malloc((strlen(save_path) + 1) * sizeof(char));
    if(!project->name){
        free(project->name);
        free(project);
        return NULL;
    }
    strcpy(project->save_path, save_path);

    project->h = h;
    project->w = w;

    project->layers = createLayers(1);
    if(!project->layers){
        free(project->name);
        free(project->save_path);
        free(project);
        return NULL;
    }

    return project;
}

void deleteProject(Project * project);

Layers * createLayers(uint capacity){
    Layers * layers = malloc(sizeof(Layers));
    if(!layers) return NULL;

    layers->layers = malloc(capacity * sizeof(Layer *));
    if(layers->layers){
        free(layers);
        return NULL;
    }

    layers->capacity = capacity;
    layers->size = 0;

    return layers;
}

void deleteLayers(Layers * layers){
    if(!layers) return;
    
    for(uint i = 0; i < layers->size; ++i){
        free(layers->layers[i]);
    }

    free(layers);
}
