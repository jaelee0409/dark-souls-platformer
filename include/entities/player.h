#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Player {
    public:
        Player();
        void update();
        void render();

    private:
        int x, y;
        int speed;
        SDL_Texture* texture;

        // Sprite sheet details
        int frameWidth, frameHeight;
        int currentFrame;
        int totalFrames;
        int animationSpeed;
        int frameTimer;
};
