cmake_minimum_required(VERSION 3.13)
project(image-corruption)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# source file liest
set(SRC_FILES src/corruption.cpp src/header.h src/img-headers.cpp)

# my goal in the end is to have multiple binaries, which execute different functions
# for example an ascii code incrementor from a=>97 to b=>98

add_executable(image-corruption ${SRC_FILES})

