#include <stdio.h>
#include "core/game.h"

int main(int argc, char *args[])
{
    Game *game = new Game();

    if (!game->init())
    {
        #ifdef _DEBUG
            printf("Game could not initialize...\n");
        #endif

        return -1;
    }

    game->run();

    delete game;

    return 0;
}
