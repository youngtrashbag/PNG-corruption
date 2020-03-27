/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: func.cpp
 */

#include "header.h"
#include "chunk/chunk.h"

using namespace std;

// check if file exists, if yes return the filename, if no return the filename in docs
string validFilename(string cmdParam)
{
	string filename = string(cmdParam);
	ifstream file(filename);

	if(file.good())
	{
		file.close();
		return filename;
	}
	else
	{
		file.close();
		// docs/sample.png
		return IMAGE_1;
	}
}

unsigned int fileSize(fstream &file)
{
	file.seekg(0, ios::end);
	unsigned int size = file.tellg();
	file.seekg(0, ios::beg);

	return size;
}

// increment the value of every char in the buffer
void Chunk::Increment(int value)
{
	vector<unsigned char>::iterator it = _typePos + 4;
	vector<unsigned char>::iterator dataEnd = _typePos + 3 + _length;

	// dataEnd is the first byte of the crc. it will stop editing before this is reached
	for(; it != dataEnd; it++)
	{
		*(it) += value;
	}

	this->UpdateCRC();
}

