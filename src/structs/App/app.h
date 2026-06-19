#ifndef APP_H
#define APP_H

#include "../../static/constants/types.h"
#include "../../static/constants/constants.h"

#include "../../static/constants/app_state.h"

#include "../Engine/engine.h"

struct _App{
    Appstate state;
    Engine * engine;
};

App * initApp(void);
void destroyApp(App * app);

#endif