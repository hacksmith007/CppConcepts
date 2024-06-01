cmake_minimum_required(VERSION 3.10)
project(ClientSender)

set(CMAKE_CXX_STANDARD 11)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Explicitly add debugging symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# Add the source files
set(CLIENT
    src/client.cpp
)

set(SERVER 
    src/server.cpp
)

# Add an include directory if needed
include_directories(include)

# Create the executable
add_executable(client ${CLIENT})
target_link_libraries(client PRIVATE rt)

add_executable(server ${SERVER})
target_link_libraries(server PRIVATE rt)



