cmake_minimum_required(VERSION 3.13)
project(image-corruption)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)

# source files for ASCII Increment
set(SRC_FILES_AI
	increment.cpp
	header.h
	func.cpp
	chunk/chunk.h
	chunk/chunk.cpp
	)

# source files for ASCII Shift
# set(SRC_FILES_AS
# 	shift.cpp
# 	header.h
# 	func.cpp
# 	chunk/chunk.h
# 	chunk/chunk.cpp
# 	)

add_executable(ascii-increment ${SRC_FILES_AI})
# add_executable(ascii-shift ${SRC_FILES_AS})

