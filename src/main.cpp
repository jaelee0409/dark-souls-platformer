#include "App/App.h"
#include <stdio.h>

int main(int argc, char* args[]) {
    App app;
    if (!app.init()) {
        printf("Failed to initialize!\n");
        return -1;
    }

    if (!app.loadMedia()) {
        printf("Failed to load media!\n");
        return -1;
    }

    app.run();
    
    return 0;
}
