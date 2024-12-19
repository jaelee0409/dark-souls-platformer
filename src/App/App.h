#pragma once

#include <SDL.h>
#include <string>
#include "Window.h"
#include "Renderer.h"
#include "Player.h"
#include "GameObject.h"
#include <vector>

class App {
public:
    App();
    ~App();

    bool init();
    bool loadMedia();
    void handleEvents();
    void run();

private:
    bool isRunning;
    Window window;
    Renderer* renderer;
    Player* player;
    std::vector<GameObject*> gameObjects;
};
