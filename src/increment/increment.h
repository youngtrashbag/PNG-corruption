/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.h
 */

#include "../header.h"

#ifndef _ASCII_INCREMENT_H_
#define _ASCII_INCREMENT_H_

// defines
#define DEFAULT_INCREMENT_AMOUNT 1

// functions
void incrementBuffer(std::vector<unsigned char> &imgVector, unsigned int incrementation);
//std::vector<unsigned char>* GetChunkBuffer(std::fstream &imageFile, char chunkName[4]);
int GetChunkBuffer(std::ifstream &imageFile, char chunkName[4]);

#endif //_ASCII_INCREMENT_H_

