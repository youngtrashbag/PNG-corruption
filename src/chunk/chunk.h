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
		/* attributes */
		// lenth/size of the chunk in bytes (big endian)
		unsigned int _length;

		// chunk type, such as "IDAT"
		char _type[5];

		//the cyclic redundancy check number
		unsigned long _cyclicRedundancyCheck;

		//the position of the first letter of the Chunk (for "IDAT" its "I")
		std::vector<unsigned char>::iterator _typePos;

		// iterator for the beginning and the end of the file
		std::vector<unsigned char> _buffer;

	public:
		/* functions */

		// constructor
		Chunk(char pType[5], std::ifstream &pFile);

		unsigned int GetLength();
		std::string GetType();
		unsigned long GetCRC();
		std::vector<unsigned char>::iterator GetBufferBeg();
		std::vector<unsigned char>::iterator GetBufferEnd();
		
		std::vector<unsigned char>::iterator LoadTypePos();
		unsigned int LoadLength();
		unsigned long LoadCRC();

		//std::vector<unsigned char> &GetData();
		//void SaveData(vector<unsigned char> &pDataBuffer);
		void UpdateCRC();

		// distortion funcs
		void Increment(int value);
};

void GetChunkInfo(Chunk &pChunk);

