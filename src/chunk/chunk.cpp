/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: chunk.cpp
 * Description:
 * 	All Functions related to Chunks
 */

#include "chunk.h"

using namespace std;

Chunk::Chunk(char pType[5], ifstream &pFile)
{
	strcpy(_type, pType);
	//loading the Chunk, becuase the Type is known
	//Chunk::_load(pFile);

	//get the position of the type
	_typePos = LoadTypePos(pFile);

	// TODO: maybe pass a vector<unsigned char> as a function param, for iterator to work with
	if(_typePos == 0)
	{
		//error;
	}
	_length = LoadLength();
	_cyclicRedundancyCheck = LoadCRC();
}



/*char[5] Chunk::GetType()
{
}*/





//other functions
/*
bool Chunk::_load(ifstream &pFile)
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

			

			// saving data to vector
			vector<unsigned char>::iterator itData = itFinder + 3;
			vector<unsigned char>::iterator itDataEnd = itCRC - 1;
			// vector<unsigned char> 
			
			for(; itData != itDataEnd; itData++)
			{
				_data.push_back(*(itData));
			}

			cout << "Chunk: " << _type << " has been found with size: " << _length;
			cout << " and CRC is: " << _cyclicRedundancyCheck << endl;
			return true;
		}
	}

	cout << "Chunk: " << _type << " could not be found" << endl;
	return false;
}
*/

void Chunk::ReCalculateCRC()
{
}

// NEW
// returns the position of the 
vector<unsigned char>::iterator Chunk::LoadTypePos(std::ifstream &pFile)
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
			return itFinder;
		}
		else
		{
			itFinder = fileBuffer.begin();
			return itFinder;
		}	
	}
}

// get the length of the chunk
unsigned int Chunk::LoadLength()
{
	// the chunk size is located 4 bytes before the chunk type
	vector<unsigned char>::iterator lenFinder = _typePos - 4;

	// get length of chunk
	unsigned char charChunkSize[] = {
		*(lenFinder),
		*(lenFinder + 1),
		*(lenFinder + 2),
		*(lenFinder + 3)
	};

	_length = 0;

	for(int i = 0; i <= 4; i++)
	{
		_length += charChunkSize[i] << 1;
		//_length += charChunkSize[i] << i;
	}
}

// this function loads the crc
int Chunk::LoadCRC()
{
	// add the remaining 3 chars of the type and the length of the chunk, to see the crc
	vector<unsigned char>::iterator crcFinder = _typePos + 3 + _length;

	// get size of chunk
	unsigned char charCRCArray[] = {
		*(crcFinder),
		*(crcFinder + 1),
		*(crcFinder + 2),
		*(crcFinder + 3)
	};

	for(int i = 0; i <= 4; i++)
	{
		_cyclicRedundancyCheck += charCRCArray[i] << 1;
		//_cyclicRedundancyCheck += charCRCArray[i] << i;
	}
}

std::vector<unsigned char> &Chunk::LoadData()
{
	// saving data to vector
	vector<unsigned char>::iterator itDataBeg = _typePos + 3;
	vector<unsigned char>::iterator itDataEnd = itDataBeg + _length;

	vector<unsigned char> dataBuffer;
	
	for(; itDataBeg != itDataEnd; itDataBeg++)
	{
		dataBuffer.push_back(*(itDataBeg));
	}

	return dataBuffer;
}
