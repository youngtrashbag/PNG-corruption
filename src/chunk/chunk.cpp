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
	// file to buffer and save as attribute
	vector<unsigned char> imageBuffer(istreambuf_iterator<char>(pFile), {});
	_imageBuffer = imageBuffer;

	//assign the private iterators i think they are
	_bufferBeg = imageBuffer.begin();
	_bufferEnd = imageBuffer.end();

	strcpy(_type, pType);

	//get the position of the type
	_typePos = LoadTypePos();

	if(_typePos == _imageBuffer.begin())
	{
		//error
		cout << "No Chunk in file" << endl;

		_length = 0;
		_cyclicRedundancyCheck = 0;
	}
	_length = LoadLength();
	_cyclicRedundancyCheck = LoadCRC();
}


unsigned int Chunk::GetLength()
{
	return _length;
}

string Chunk::GetType()
{
	return _type;
}

int Chunk::GetCRC()
{
	return _cyclicRedundancyCheck;
}



// NEW
// returns the position of the Chunk Type/Name ("IDAT" -> "I")
vector<unsigned char>::iterator Chunk::LoadTypePos()
{

	// itFinder -> iteratorFinder
	vector<unsigned char>::iterator typeFinder = _imageBuffer.begin();
	typeFinder += 8; // advance 8 bytes, because of PNG Signature

	// find the ChunkType
	
	// TODO: fix the dilemma, how i am going to get the end() and begin() of the vector
	for(; typeFinder != _imageBuffer.end(); typeFinder++)
	{
		if(
			*(typeFinder) == (unsigned) _type[0] &&
			*(typeFinder+1) == (unsigned) _type[1] &&
			*(typeFinder+2) == (unsigned) _type[2] &&
			*(typeFinder+3) == (unsigned) _type[3]
		  )
		{
			return typeFinder;
		}
	}

	// in case the chunk is not found, return the beginning of the file
	typeFinder = _imageBuffer.begin();
	return typeFinder;
}

// get the length of the chunk
unsigned int Chunk::LoadLength()
{
	// the chunk size is located 4 bytes before the chunk type
	vector<unsigned char>::iterator lenFinder = _imageBuffer.begin();
	lenFinder = _typePos - 4;

	// get length of chunk
	unsigned char charChunkSize[5] = {
		*(lenFinder),
		*(lenFinder + 1),
		*(lenFinder + 2),
		*(lenFinder + 3)
	};

	unsigned int length = 0;

	for(int i = 0; i < 4; i++)
	{
		length += charChunkSize[i] << 1;
	}

	length = length >> 1;
	return length;
}

// this function loads the crc
int Chunk::LoadCRC()
{
	// add the remaining 3 chars of the type and the length of the chunk, to see the crc
	vector<unsigned char>::iterator crcFinder = _imageBuffer.begin();
	crcFinder = _typePos + 3 + _length;

	// get size of chunk
	unsigned char charCRCArray[5] = {
		*(crcFinder),
		*(crcFinder + 1),
		*(crcFinder + 2),
		*(crcFinder + 3)
	};

	int cyclicRedundancyCheck = 0;

	for(int i = 0; i <= 4; i++)
	{
		cyclicRedundancyCheck += charCRCArray[i] << 1;
	}

	cyclicRedundancyCheck = cyclicRedundancyCheck >> 1;
	return cyclicRedundancyCheck;
}

/*
vector<unsigned char> &Chunk::GetData()
{
	// saving data to vector
	vector<unsigned char>::iterator itDataBeg = _imageBuffer.begin();
	itDataBeg = _typePos + 3;
	vector<unsigned char>::iterator itDataEnd = itDataBeg + _length;

	vector<unsigned char> dataBuffer;
	
	for(; itDataBeg != itDataEnd; itDataBeg++)
	{
		dataBuffer.push_back(*(itDataBeg));
	}

	return dataBuffer;
}
*/

/*
// saves the data to the original image buffer
void Chunk::SaveData(vector<unsigned char> &pDataBuffer)
{
	// saving data to vector
	vector<unsigned char>::iterator itDataBeg = _imageBuffer.begin();
	itDataBeg = _typePos + 3;
	vector<unsigned char>::iterator itDataEnd = itDataBeg + _length;

	vector<unsigned char> dataBuffer;
	
	for(; itDataBeg != itDataEnd; itDataBeg++)
	{
		dataBuffer.push_back(*(itDataBeg));
	}

}
*/

// Display the Infos of a Chunk.
void GetChunkInfo(Chunk &pChunk)
{
	cout << "Chunk Type: " << pChunk.GetType() << endl;
	cout << "Chunk Length: " << pChunk.GetLength() << endl;
	cout << "Chunk CRC: " << pChunk.GetCRC() << endl;
}

void Chunk::ReCalculateCRC()
{
}

