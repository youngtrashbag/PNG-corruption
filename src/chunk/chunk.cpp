/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: chunk.cpp
 * Description:
 * 	All Functions related to Chunks
 */

# include "chunk.h"

Chunk::Chunk(unsigned int pLength)
{
	_length = pLength;
}

unsigned int Chunk::GetLength()
{
}

char[5] Chunk::GetType()
{
}

&std::vector<unsigned char> Chunk::GetData()
{
}

int Chunk::GetCRC()
{
}

//other functions
void Chunk::ReCalculateCRC()
{
}

// return buffer to chunk from image
// TODO: this needs to return a vector<unsigned char>
// TODO: also this is the GetData function, just needs to be recoded
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


