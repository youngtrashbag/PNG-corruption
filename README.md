# PNG Corruption

## Introduction

This is a tool, that can corrupt PNG Images and therefore create Interesting Visual Artifacts.  
Focused on IDAT Chunk.

## Prerequisites

- Cmake
- Clang

## Installation

1. `cd bin`
2. `cmake ..`
3. `make`
4. Run the newly created binary (in case you don't use an image, the default image will be used)  
`./png-corruption`  
`./png-corruption -f my-image.png -o out.png --info --increment 1`

## License

[GNU General Public License v3.0](./LICENSE)

