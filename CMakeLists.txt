cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(DarkSoulsPlatformer)

# Find the SDL2 package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Automatically collect all .cpp files in src
file(GLOB SOURCES
    src/main.cpp
    src/App/*.cpp
    src/Core/*.cpp
    src/Systems/*.cpp
)

# Create the executable
add_executable(DarkSoulsPlatformer ${SOURCES})

# Link the SDL2 and SDL2_image libraries
target_link_libraries(DarkSoulsPlatformer 
    SDL2::SDL2 
    SDL2_image::SDL2_image
)

# Define SDL_MAIN_HANDLED to prevent SDL2 from defining its own main
add_definitions(-DSDL_MAIN_HANDLED)

include_directories(${PROJECT_SOURCE_DIR}/src/App)
include_directories(${PROJECT_SOURCE_DIR}/src/Core)
include_directories(${PROJECT_SOURCE_DIR}/src/Systems)
