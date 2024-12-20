#include <SDL.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "input/input.h"

Player::Player() {
    // Set initial position
    x = 100;
    y = 100;
    speed = 5;
    texture = nullptr;

    // Load player sprite
    SDL_Surface* surface = SDL_LoadBMP("assets/sprites/player.bmp");
    texture = SDL_CreateTextureFromSurface(Graphics::renderer, surface);
    SDL_FreeSurface(surface);
}

void Player::update() {
    // Simple movement logic
    if (Input::keyPressed(SDL_SCANCODE_W)) {
        y -= speed;  // Move up
    }
    if (Input::keyPressed(SDL_SCANCODE_S)) {
        y += speed;  // Move down
    }
    if (Input::keyPressed(SDL_SCANCODE_A)) {
        x -= speed;  // Move left
    }
    if (Input::keyPressed(SDL_SCANCODE_D)) {
        x += speed;  // Move right
    }
}

void Player::render() {
    // Render the player sprite at the current position
    SDL_Rect dstRect = {x, y, 32, 32};  // Example size
    SDL_RenderCopy(Graphics::renderer, texture, nullptr, &dstRect);
}
