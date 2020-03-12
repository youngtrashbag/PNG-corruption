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

		// function that get executed in the ctor
		bool _load(std::ifstream &pFile);

	public:
		// constructor
		Chunk(char pType[5], std::vector<unsigned char> &pFileBuffer);
		
		// functions
		//char[5] GetType();
		
		void ReCalculateCRC();

		//new
		std::vector<unsigned char>::iterator LoadTypePos(std::vector<unsigned char> &pFileBuffer);
		unsigned int LoadLength(std::vector<unsigned char> &pFileBuffer);
		int LoadCRC(std::vector<unsigned char> &pFileBuffer);
		std::vector<unsigned char> &LoadData(std::vector<unsigned char> &pFileBuffer);
};

