cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(DarkSoulsPlatformer)

# Set the SDL2 directories (make sure it points to the location of Config.cmake)
# set(SDL2_DIR "${PROJECT_SOURCE_DIR}\libs\SDL2\lib\cmake\SDL2")
# set(SDL2_image_DIR "${PROJECT_SOURCE_DIR}\libs\SDL2\lib\cmake\SDL2_image")

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

# Include SDL2 header files
# include_directories(${SDL2_INCLUDE_DIRS})
# include_directories(${SDL2_image_INCLUDE_DIRS})

# Link the SDL2 libraries
# target_link_libraries(DarkSoulsPlatformer ${SDL2_LIBRARIES})
# target_link_libraries(DarkSoulsPlatformer ${SDL2_image_LIBRARIES})

# Define SDL_MAIN_HANDLED to prevent SDL2 from defining its own main
add_definitions(-DSDL_MAIN_HANDLED)

include_directories(${PROJECT_SOURCE_DIR}/src/App)
include_directories(${PROJECT_SOURCE_DIR}/src/Core)
include_directories(${PROJECT_SOURCE_DIR}/src/Systems)
