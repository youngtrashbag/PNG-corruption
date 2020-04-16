cmake_minimum_required(VERSION 3.13)
project(mandelbrot)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER clang)

# source files for ASCII Increment
set(SRC_FILES
	src/main.c
	src/header.h
	)

find_package(libpng REQUIRED)
# include_directories(${PNG_INCLUDE_DIR})

# make string to lower for executable filename
string(TOLOWER ${PROJECT_NAME} BIN_NAME)

add_executable(${BIN_NAME} ${SRC_FILES})

target_link_libraries(${BIN_NAME} ${libpng_LIBS})
