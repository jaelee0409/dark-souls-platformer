#pragma once

#include <SDL.h>

class Player {
    public:
        Player();
        void update();
        void render();

    private:
        int x, y;
        int speed;
        SDL_Texture* texture;
};
