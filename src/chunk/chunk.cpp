/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: chunk.cpp
 * Description:
 * 	All Functions related to Chunks
 */

#include "chunk.h"

using namespace std;

Chunk::Chunk(char pType[5])
{
	strcpy(_type, pType);
	//loading the Chunk, becuase the Type is known
	//Chunk::Load(pFile);
}

unsigned int Chunk::GetLength()
{
}

/*char[5] Chunk::GetType()
{
}*/

std::vector<unsigned char> &Chunk::GetData()
{
}

int Chunk::GetCRC()
{
}

//other functions
void Chunk::Load(ifstream &pFile)
{
	vector<unsigned char> fileBuffer(istreambuf_iterator<char>(pFile), {});

	// file has been loaded into buffer
	// it can be closed now
	pFile.close();

	vector<unsigned char>::iterator itFinder = fileBuffer.begin();
	itFinder += 8; // advance 8 bytes, because of PNG Signature

	// find the ChunkType
	
	bool chunkIsPresent = false;
	unsigned char charChunkSize[4];

	for(; itFinder != fileBuffer.end(); itFinder++)
	{
		if(
			*(itFinder) == (unsigned) _type[0] &&
			*(itFinder+1) == (unsigned) _type[1] &&
			*(itFinder+2) == (unsigned) _type[2] &&
			*(itFinder+3) == (unsigned) _type[3]
		  )
		{
			// the chunk type has been found
			chunkIsPresent = true;

			// get size of chunk
			unsigned char charSizeArr[] = {
				*(itFinder - 4),
				*(itFinder - 3),
				*(itFinder - 2),
				*(itFinder - 1)
			};
			
			memcpy(charChunkSize, charSizeArr, sizeof charChunkSize);
		}
	}

	if(chunkIsPresent)
	{

		// calculate the 4byte uint charSize
		_length = 0;

		for(int i = 0; i <= 4; i++)
		{
			_length += charChunkSize[i] << 1;
		}

		cout << "Chunk: " << _type << " has been found with size: " << _length << endl;

	}
	else
	{
		cout << "Chunk: " << _type << " could not be found" << endl;
	}


}

void Chunk::ReCalculateCRC()
{
}

/*
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
*/

