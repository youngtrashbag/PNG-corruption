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

	// itFinder -> iteratorFinder
	vector<unsigned char>::iterator itFinder = fileBuffer.begin();
	itFinder += 8; // advance 8 bytes, because of PNG Signature

	// find the ChunkType
	
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
			
			// position for length
			vector<unsigned char>::iterator itLength = itFinder - 4;

			// create new iterator, to not mess up the basic one
			// the tempFinder is now located at first char of chunkName

			// get length of chunk
			unsigned char charChunkSize[] = {
				*(itLength),
				*(itLength + 1),
				*(itLength + 2),
				*(itLength + 3)
			};

			_length = 0;

			for(int i = 0; i <= 4; i++)
			{
				_length += charChunkSize[i] << 1;
				//_length += charChunkSize[i] << i;
			}

			// position for the CRC
			vector<unsigned char>::iterator itCRC = itFinder + 3 + _length;

			// get size of chunk
			unsigned char charCRCArray[] = {
				*(itCRC),
				*(itCRC + 1),
				*(itCRC + 2),
				*(itCRC + 3)
			};

			for(int i = 0; i <= 4; i++)
			{
				_cylicRedundancyCheck += charCRCArray[i] << 1;
			}

			// saving data to vector
			vector<unsigned char>::iterator itData = itFinder + 3;
			vector<unsigned char>::iterator itDataEnd = itCRC - 1;
			// vector<unsigned char> 
			
			for(; itData != itDataEnd; itData++)
			{
				_data.push_back(*(itData));
			}

			cout << "Chunk: " << _type << " has been found with size: " << _length;
			cout << " and CRC is: " << _cylicRedundancyCheck << endl;
			return true;
		}
	}

	cout << "Chunk: " << _type << " could not be found" << endl;
	return false;
}

void Chunk::ReCalculateCRC()
{
}

