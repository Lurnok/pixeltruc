#include "app.h"
#include <stdlib.h>

App * initApp(void){
    App * app = malloc(sizeof(App));
    if(!app) return NULL;

    app->engine = createEngine();
    if(!app->engine){
        free(app);
        return NULL;
    }

    app->state = MAINMENU;

    return app;
}

void destroyApp(App * app){
    if(!app) return;
    destroyEngine(app->engine);
    free(app);
}