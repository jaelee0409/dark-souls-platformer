#include <SDL.h>
#include <SDL_image.h>
#include "entities/player.h"
#include "graphics/graphics.h"
#include "graphics/animation.h"
#include "input/input.h"

Player::Player(float _x, float _y, float _speed)
{
    x = _x;
    y = _y;
    speed = _speed;
    velocityY = 0;
    gravity = 0.5f;
    jumpSpeed = -12.0f;
    isJumping = false;
    isRolling = false;

    // Load idle animation
    #ifdef _DEBUG
        printf("Loading player idle animation...\n");
    #endif
    Animation idleAnimation;
    if (!idleAnimation.load_animation("../assets/sprites/_Idle.png", 120, 80, 10, 300)) {
        #ifdef _DEBUG
            printf("Failed to load Idle animation texture.\n");
        #endif
    }
    animations["Idle"] = idleAnimation;

    // Load run animation
    #ifdef _DEBUG
        printf("Loading player run animation...\n");
    #endif
    Animation runAnimation;
    if (!runAnimation.load_animation("../assets/sprites/_Run.png", 120, 80, 10, 200)) {
        #ifdef _DEBUG
            printf("Failed to load Run animation texture.\n");
        #endif
    }
    animations["Run"] = runAnimation;

    // Start in idle state
    currentState = PlayerState::Idle;
    set_animation("Idle");

    #ifdef _DEBUG
        printf("Player initialized...\n");
    #endif
}

void Player::update(float deltaTime)
{
    // Movement logic (frame rate independent)
    if (Input::keyPressed(SDL_SCANCODE_UP) && !isJumping)
    {
        #ifdef _DEBUG
            printf("Jumping...\n");
        #endif

        isJumping = true;      // Trigger jump
        velocityY = jumpSpeed; // Set the jump speed
    }
    if (Input::keyPressed(SDL_SCANCODE_DOWN))
    {
        #ifdef _DEBUG
            printf("Crouching...\n");
        #endif

        // Implement crouch behavior (modify later)
    }
    if (Input::keyPressed(SDL_SCANCODE_LEFT))
    {
        #ifdef _DEBUG
            printf("Running left...\n");
        #endif

        x -= speed * deltaTime;              // Move left (speed is multiplied by deltaTime)
        currentState = PlayerState::Running; // Change state to walking
    }
    if (Input::keyPressed(SDL_SCANCODE_RIGHT))
    {
        #ifdef _DEBUG
            printf("Running right...\n");
        #endif

        x += speed * deltaTime;              // Move right (speed is multiplied by deltaTime)
        currentState = PlayerState::Running; // Change state to walking
    }

    // Handle gravity when jumping
    if (isJumping)
    {
        y += velocityY * deltaTime;       // Apply velocity with deltaTime for frame-rate independent movement
        velocityY += gravity * deltaTime; // Apply gravity with deltaTime

        // Stop the jump when the player lands
        if (y >= 100) // Example ground level; adjust as needed
        {
            y = 100; // Set to the ground level
            isJumping = false;
        }
    }

    // Update animation frame based on the current state
    currentAnimation->frameTimer++;
    if (currentAnimation->frameTimer >= currentAnimation->animationSpeed)
    {
        currentAnimation->frameTimer = 0;
        currentAnimation->currentFrame = (currentAnimation->currentFrame + 1) % currentAnimation->totalFrames; // Loop through frames
    }

    // Update player state (switch to idle when not moving)
    if (currentState == PlayerState::Running && !Input::keyPressed(SDL_SCANCODE_LEFT) && !Input::keyPressed(SDL_SCANCODE_RIGHT))
    {
        currentState = PlayerState::Idle; // Switch to idle state when no movement keys are pressed
    }
}

void Player::render()
{
    // Check if the renderer is initialized
    if (!Graphics::renderer) {
        #ifdef _DEBUG
            printf("Error: SDL_Renderer is not initialized!\n");
        #endif

        return;
    }

    if (!currentAnimation || !currentAnimation->texture) {
        #ifdef _DEBUG
            printf("Error: No texture available for the player animation.\n");
        #endif

        return;
    }

    // Calculate the source rectangle for the current animation frame
    SDL_Rect srcRect;
    srcRect.x = currentAnimation->currentFrame * currentAnimation->frameWidth;
    srcRect.y = 0;
    srcRect.w = currentAnimation->frameWidth;
    srcRect.h = currentAnimation->frameHeight;

    // Define the destination rectangle for rendering the sprite
    SDL_Rect dstRect = {static_cast<int>(x), static_cast<int>(y), currentAnimation->frameWidth, currentAnimation->frameHeight};

    printf("srcRect: x=%d, y=%d, w=%d, h=%d\n", srcRect.x, srcRect.y, srcRect.w, srcRect.h);
    printf("dstRect: x=%d, y=%d, w=%d, h=%d\n", dstRect.x, dstRect.y, dstRect.w, dstRect.h);


    if (!currentAnimation->texture) {
        #ifdef _DEBUG
            printf("Texture is invalid: %s\n", SDL_GetError());
        #endif
        
        return;
    }

    // Render the current frame of the player's animation
    if (SDL_RenderCopy(Graphics::renderer, currentAnimation->texture, &srcRect, &dstRect) != 0) {
        #ifdef _DEBUG
            printf("Error rendering texture... : %s\n", SDL_GetError());
        #endif

        return;
    }
}

void Player::set_animation(const std::string &animationName)
{
    #ifdef _DEBUG
        printf("Setting player animation...\n");
    #endif

    // Change the current animation if it exists
    if (animations.find(animationName) != animations.end())
    {
        currentAnimation = &animations[animationName];
    }
    else
    {
        #ifdef _DEBUG
            printf("Warning: Animation '%s' not found!\n", animationName.c_str());
        #endif
    }

    #ifdef _DEBUG
        printf("Finished setting player animation...\n");
    #endif
}