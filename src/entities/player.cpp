#include <SDL.h>
#include <SDL_image.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "input/input.h"

Player::Player() {
    // Set initial position
    x = 100;
    y = 100;
    speed = 0.1;
    texture = nullptr;

    // Load player sprite
    SDL_Surface* surface = IMG_Load("../assets/sprites/_Idle.png");
    if (surface == nullptr) {
        printf("Failed to load player sprite sheet! SDL_image Error: %s\n", IMG_GetError());
    }

    texture = SDL_CreateTextureFromSurface(Graphics::renderer, surface);
    SDL_FreeSurface(surface);

    // Initialize sprite sheet properties
    frameWidth = 120; // Width of one frame in the sprite sheet
    frameHeight = 80; // Height of one frame in the sprite sheet
    currentFrame = 0; // Start at the first frame
    totalFrames = 10; // Assume there are 4 frames in the sprite sheet
    animationSpeed = 0.1; // How fast the animation frames should change
    frameTimer = 0; // Timer to track the frame changes
}

void Player::update() {
    // Simple movement logic
    if (Input::keyPressed(SDL_SCANCODE_UP)) {
        printf("UP\n");
        y -= speed;  // Move up
    }
    if (Input::keyPressed(SDL_SCANCODE_DOWN)) {
        printf("DOWN\n");
        y += speed;  // Move down
    }
    if (Input::keyPressed(SDL_SCANCODE_LEFT)) {
        printf("LEFT\n");
        x -= speed;  // Move left
    }
    if (Input::keyPressed(SDL_SCANCODE_RIGHT)) {
        printf("RIGHT\n");
        x += speed;  // Move right
    }

    // Update animation frame
    frameTimer++;
    if (frameTimer >= animationSpeed) {
        frameTimer = 0;
        currentFrame = (currentFrame + 1) % totalFrames;  // Loop through frames
    }
}

void Player::render() {
    // Calculate the source rectangle for the current animation frame
    SDL_Rect srcRect;
    srcRect.x = currentFrame * frameWidth;  // Select the correct frame's X position in the sprite sheet
    srcRect.y = 0;  // Assuming all frames are in one row (Y is always 0)
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;

    // Define the destination rectangle for rendering the sprite
    SDL_Rect dstRect = {x, y, frameWidth, frameHeight};

    // Render the current frame of the player sprite
    SDL_RenderCopy(Graphics::renderer, texture, &srcRect, &dstRect);
}
