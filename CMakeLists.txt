cmake_minimum_required(VERSION 3.13)
project(PNG-corruption)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# source files for ASCII Increment
set(SRC_FILES_AI
	src/increment.cpp
	src/header.h
	src/func.cpp
	src/argument/argument.h
	src/argument/argument.cpp
	src/chunk/chunk.h
	src/chunk/chunk.cpp
	src/chunk/crc.cpp
	src/distortion/increment-func.cpp
	)

add_executable(${PROJECT_NAME} ${SRC_FILES_AI})

