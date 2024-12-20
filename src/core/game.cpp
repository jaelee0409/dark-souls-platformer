#include <SDL.h>
#include "graphics/graphics.h"
#include "input/input.h"
//#include "audio/audio.h"
//#include "level/level.h"
//#include "entities/player.h"
#include "core/game.h"

// Game initialization and main loop
bool Game::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    // Initialize game subsystems
    if (!Graphics::init()) {
        printf("Graphics initialization failed!\n");
        return false;
    }
    if (!Input::init()) {
        printf("Input initialization failed!\n");
        return false;
    }
    //if (!Audio::init()) {
    //    printf("Audio initialization failed!\n");
    //    return false;
    //}

    return true;
}

void Game::run() {
    // Load the first level
    //Level level;
    //level.load("assets/levels/level1.json");

    // Create the player
    //Player player;

    isRunning = true;
    while (isRunning) {
        // Handle events (input)
        Input::processInput();

        // Update game entities
        //player.update();
        
        // Update level/physics
        //level.update();

        // Render the frame
        Graphics::clear();
        //level.render();
        //player.render();
        Graphics::present();

        // Check if the player wants to quit
        if (Input::keyPressed(SDL_SCANCODE_ESCAPE)) {
            isRunning = false;
        }
    }

    // Clean up
    //Audio::cleanup();
    Graphics::cleanup();
    SDL_Quit();
}