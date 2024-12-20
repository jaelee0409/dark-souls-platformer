#pragma once

#include <string>

class Level {
    public:
        void load(const std::string& filename);
        void update();
        void render();
};
