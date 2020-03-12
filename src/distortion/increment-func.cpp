/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: increment-func.cpp
 * Description:
 * 	Functions for the Increment Process.
 */

#include "../header.h"
#include "../chunk/chunk.h"

using namespace std;

// increment the value of every char in the buffer
void Chunk::Increment(int value)
{
	vector<unsigned char>::iterator it = _typePos + 4;
	vector<unsigned char>::iterator dataEnd = _typePos + 4 + _length;

	for(; it != dataEnd; it++)
	{
		*it += value;
	}
	
}

