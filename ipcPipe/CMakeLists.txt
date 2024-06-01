cmake_minimum_required(VERSION 3.10)
project(IpcPipce)

set(CMAKE_CXX_STANDARD 11)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Explicitly add debugging symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# Add the source files
set(PIPE
    src/pipe.cpp
)

# Add an include directory if needed
include_directories(include)

# Create the executable
add_executable(pipe ${PIPE})




