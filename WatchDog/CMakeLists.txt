cmake_minimum_required(VERSION 3.10)
project(registerMultipleCallbacks)

set(CMAKE_CXX_STANDARD 11)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Explicitly add debugging symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# Add the source files
set(SOURCES
    src/main.cpp
    src/callbacks.cpp
)

# Add an include directory if needed
include_directories(include)

# Create the executable
add_executable(registerMultipleCallbacks ${SOURCES})

# Link the required libraries
target_link_libraries(registerMultipleCallbacks pthread)
