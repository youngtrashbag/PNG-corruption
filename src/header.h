/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: header.h
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>

#ifndef _HEADER_H_
#define _HEADER_H_

// defines
#define IMAGE_1 "sample.png"
#define IMAGE_2 "png.png"
#define IMAGE_3 "lena.png"

// functions
std::string validFilename(std::string cmdParam);
unsigned int fileSize(std::fstream &file);

// increment functions
void incrementBuffer(std::vector<unsigned char> &buffer, unsigned int incrementation);
int GetChunkBuffer(std::ifstream &imageFile, char chunkName[4]);

#endif //_HEADER_H_

