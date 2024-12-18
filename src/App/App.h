#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <string>
#include "Window.h"
#include "Renderer.h"

class App {
public:
    App();
    ~App();

    bool init();
    bool loadMedia();
    void handleEvents();
    void run();

private:
    Window window;
    Renderer* renderer;
    bool quit;
};

#endif