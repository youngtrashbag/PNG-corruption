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
bool Chunk::Load(ifstream &pFile)
{
	vector<unsigned char> fileBuffer(istreambuf_iterator<char>(pFile), {});

	vector<unsigned char>::iterator itFinder = fileBuffer.begin();
	itFinder += 8; // advance 8 bytes, because of PNG Signature

	// find the ChunkType
	
	bool chunkIsPresent = false;
	unsigned char charChunkSize[4];
	unsigned char charCRC[4];

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

			// get size of chunk
			unsigned char charCRCArray[] = {
				*(itFinder - 4),
				*(itFinder - 3),
				*(itFinder - 2),
				*(itFinder - 1)
			};

			itPos = itFinder;
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

		// get the CRC
		itFinder = itPos;
		//3 becuase its position is at the first byte of the type
		itFinder += 3 + _length;
		_cylicRedundancyCheck = {
			*(itFinder+1),
			*(itFinder+2),
			*(itFinder+3),
			*(itFinder+4)
		};

		cout << "Chunk: " << _type << " has been found with size: " << _length;
		cout << " and CRC is: " << _cylicRedundancyCheck << endl;
		return true;

	}
	else
	{
		cout << "Chunk: " << _type << " could not be found" << endl;
		return false;
	}


}

void Chunk::ReCalculateCRC()
{
}

