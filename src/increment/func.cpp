/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.cpp
 */

#include "increment.h"

using namespace std;

void incrementBuffer(vector<unsigned char> &imgVector, unsigned int incrementation)
{
	vector<unsigned char>::iterator it = imgVector.begin();

	//1. skip header
	//i know that png header is 4bytes and 1 unsigned char is 1byte; therefore
	it += 4;

	//2. increment other chars
	for(; it != imgVector.end(); it++)
	{
		if(*it >= 32 && *it < 126)
		{
			*it += incrementation;
		}
	}
}

//return buffer to chunk from image
//vector<unsigned char>* GetChunkBuffer(fstream &imageFile, char[4] chunkName)
int GetChunkBuffer(ifstream &imageFile, char chunkName[4])
{
	//contains the newly opened image as a whole
	vector<unsigned char> imageBuffer(istreambuf_iterator<char>(imageFile), {});

	//pointer "array" type of thing
	vector<unsigned char>::iterator bufferIterator = imageBuffer.begin();

	for(; bufferIterator != imageBuffer.end(); bufferIterator++)
	{
		if(*bufferIterator == chunkName[0])
		{
			//i think this makes the program faster
			if(*(bufferIterator + 1) == chunkName[1] &&
				*(bufferIterator + 2) == chunkName[2] &&
				*(bufferIterator + 3) == chunkName[3])
			{
				//chunk name matches
				//get length of chunk
				unsigned char len[4] = { *(bufferIterator - 4),
						*(bufferIterator - 3),
						*(bufferIterator - 2),
						*(bufferIterator - 1)
						};

				unsigned int chunkLength = 0;

				for(int i = 0; i <= 4; i++)
				{
					chunkLength += len[i] << 1;
				}

				return chunkLength;
			}
		}

	}
	
}

