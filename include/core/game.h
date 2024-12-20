#pragma once

#include <SDL.h>
//#include "graphics/graphics.h"
//#include "input/input.h"
//#include "audio/audio.h"
//#include "level/level.h"
//#include "entities/player.h"
//#include "core/game.h"

class Game {
    public:
        bool init();
        void run();

    private:
        bool isRunning;
};
