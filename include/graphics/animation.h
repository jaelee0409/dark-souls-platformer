#pragma once

#include <SDL.h>

#include <SDL.h>
#include <string>

class Animation {
public:
    SDL_Texture* texture = nullptr;
    int frameWidth;
    int frameHeight;
    int totalFrames;
    int currentFrame;
    int animationSpeed;
    int frameTimer;

    Animation();
    ~Animation();

    bool load_animation(const std::string& filePath, int frameWidth, int frameHeight, int totalFrames, int animationSpeed);
};