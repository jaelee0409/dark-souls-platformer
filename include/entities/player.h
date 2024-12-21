#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>
#include <graphics/animation.h>
#include "input/input.h"

class Player
{
public:
    Player(float x, float y, float speed);

    void update(float deltaTime);
    void render();
    void handle_input();

    float get_x() const { return x; }
    float get_y() const { return y; }
    void set_position(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

private:
    float x, y;
    float speed;
    float velocityY; // Vertical velocity for jumping (affected by gravity)
    float gravity;   // Gravity strength pulling the player down
    bool isJumping;
    bool isRolling;
    float jumpSpeed;    // Speed at which the player jumps
    float rollSpeed;    // Speed at which the player rolls
    float rollDuration; // Duration of the roll
    float rollTimer;    // Timer to track roll duration

    std::unordered_map<std::string, Animation> animations; // Store all animations by name
    Animation* currentAnimation; // Pointer to the current animation

    enum class PlayerState
    {
        Idle = 0,
        Running,
        Jumping,
        Crouching,
        CrouchWalking,
        Rolling,
        Death
    };
    PlayerState currentState;

    // Animation frames (sprites for different actions)
    SDL_Texture *idleSheet;    // Idle animation sprite sheet
    SDL_Texture *walkingSheet; // Walking animation sprite sheet
    SDL_Texture *jumpSheet;    // Jump animation sprite sheet
    SDL_Texture *crouchSheet;  // Crouch animation sprite sheet
    SDL_Texture *rollSheet;    // Roll animation sprite sheet

    // Dimensions for each individual frame in the sprite sheet
    int frameWidth, frameHeight;

    void set_animation(const std::string &animationName);

    // Update animation frames based on the player's state
    void update_animation(float deltaTime);

    // Load animation frames (can be called during initialization)
    void load_textures(SDL_Renderer *renderer);

    // Extract a frame from the sprite sheet
    SDL_Rect get_frame_rect(int frameIndex, int totalFramesInRow);

    // Clean up resources when the player object is destroyed
    void cleanup();
};