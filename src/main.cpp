#include <stdio.h>
#include "core/game.h"

int main(int argc, char *args[])
{
    Game game;

    if (!game.init())
    {
#ifdef _DEBUG
        printf("Game could not initialize...\n");
#endif
        return -1;
    }

    game.run();

    return 0;
}
