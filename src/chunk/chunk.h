/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: chunk.h
 * Description:
 * 	Header File for Chunk related functions.
 */

#include "../header.h"

class Chunk
{
	private:
		// lenth/size of the chunk in bytes (big endian)
		unsigned int _length;
		// chunk type, such as "IDAT"
		char _type[5];
		//the cyclic redundancy check number
		int _cyclicRedundancyCheck;
		//the position of the first letter of the Chunk (for "IDAT" its "I")
		std::vector<unsigned char>::iterator _typePos;
		// buffer for the whole ass file
		std::vector<unsigned char> _imageBuffer;

		// function that get executed in the ctor
		bool _load(std::ifstream &pFile);

	public:
		// constructor
		Chunk(char pType[5], std::ifstream &pFile);

		// get & set
		unsigned int GetLength();
		std::string GetType();
		int GetCRC();
		
		// functions
		//char[5] GetType();
		
		void ReCalculateCRC();

		//new
		std::vector<unsigned char>::iterator LoadTypePos();
		unsigned int LoadLength();
		int LoadCRC();
		//std::vector<unsigned char> &GetData();
		//void SaveData(vector<unsigned char> &pDataBuffer);
};

void GetChunkInfo(Chunk &pChunk);

