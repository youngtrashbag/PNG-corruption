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
		char[5] _type;
		// reference to chunk data
		&std::vector<unsigned char> _data;
		int _cylicRedundancyCheck;

	public:
		// constructor
		Chunk(char[5] pType);
		
		// get
		unsigned int GetLength();
		char[5] GetType();
		&std::vector<unsigned char> GetData();
		int GetCRC();

		//other functions
		void ReCalculateCRC();
}

