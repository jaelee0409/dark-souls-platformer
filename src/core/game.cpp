#include <SDL.h>
#include "graphics/graphics.h"
#include "input/input.h"
// #include "audio/audio.h"
// #include "level/level.h"
#include "entities/player.h"
#include "core/game.h"

// Game initialization and main loop
bool Game::init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
#ifdef _DEBUG
        printf("SDL could not initialize... SDL_Error: %s\n", SDL_GetError());
#endif
        return false;
    }

    // Initialize game subsystems
    if (!Graphics::init())
    {
#ifdef _DEBUG
        printf("Graphics initialization failed...\n");
#endif
        return false;
    }
    if (!Input::init())
    {
#ifdef _DEBUG
        printf("Input initialization failed...\n");
#endif

        return false;
    }
    // if (!Audio::init()) {
    //     printf("Audio initialization failed!\n");
    //     return false;
    // }

    return true;
}

void Game::run()
{
    // Load the first level
    // Level level;
    // level.load("assets/levels/level1.json");

    // Create the player
    Player player(100.0f, 100.0f, 0.1f);

    isRunning = true;
    Uint32 lastTime = SDL_GetTicks();
    while (isRunning)
    {
        // Calculate deltaTime (time passed since the last frame)
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f; // Convert to seconds
        lastTime = currentTime;

        // Handle events (input)
        Input::processInput();

        // Update game entities
        player.update(deltaTime);

        // Update level/physics
        // level.update();

        // Render the frame
        Graphics::clear();
        // level.render();
        player.render();
        Graphics::present();

        // Check if the player wants to quit
        if (Input::keyPressed(SDL_SCANCODE_ESCAPE))
        {
            isRunning = false;
        }
    }

    // Clean up
    // Audio::cleanup();
    Graphics::cleanup();
    SDL_Quit();
}