#include <SDL_image.h>
#include <string>
#include "graphics/graphics.h"
#include "graphics/animation.h"

// Constructor
Animation::Animation() 
    : texture(nullptr), frameWidth(0), frameHeight(0), totalFrames(0), currentFrame(0), animationSpeed(100), frameTimer(0) {}

// Destructor
Animation::~Animation() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

bool Animation::loadAnimation(const std::string &filePath, int frameWidth, int frameHeight, int totalFrames, int animationSpeed)
{
    // Load texture
    SDL_Surface *surface = IMG_Load(filePath.c_str());
    if (!surface)
    {
#ifdef _DEBUG
        printf("Failed to load texture : %s : %s\n", filePath, SDL_GetError());
#endif
        return false;
    }

    texture = SDL_CreateTextureFromSurface(Graphics::renderer, surface);
    SDL_FreeSurface(surface);

    // Set the frame and animation properties
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->totalFrames = totalFrames;
    this->animationSpeed = animationSpeed;

    // Reset the frame counters
    this->currentFrame = 0;
    this->frameTimer = 0;

    return true;
}
