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

#ifndef _HEADER_H_
#define _HEADER_H_

// defines
#define IMAGE_1 "sample.png"
#define IMAGE_2 "lena.png"

// functions
std::string validFilename(std::string cmdParam);
unsigned int fileSize(std::fstream &file);

#endif //_HEADER_H_

