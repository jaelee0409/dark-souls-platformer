cmake_minimum_required(VERSION 3.10)

project(DarkSoulsPlatformer)

# Set the SDL2 directory (make sure it points to the location of SDL2Config.cmake)
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/cmake/SDL2")

# Find the SDL2 package
find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

# Automatically collect all .cpp files in src
file(GLOB SOURCES
    src/*.cpp
    src/*/*.cpp
)

# Create the executable
add_executable(DarkSoulsPlatformer ${SOURCES})

# Include SDL2 header files
include_directories(${SDL2_INCLUDE_DIRS})

# Link the SDL2 libraries
target_link_libraries(DarkSoulsPlatformer ${SDL2_LIBRARIES})

# If using SDL2_image, uncomment and configure it similarly
target_link_libraries(DarkSoulsPlatformer ${SDL2_image_LIBRARIES})
include_directories(${SDL2_image_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/Core)