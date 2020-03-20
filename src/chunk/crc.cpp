/*
 * Author: youngtrashbag
 * Date: 18.03.2020
 * File: crc.cpp
 * Description:
 * 	Functions and Code related to the Calculation
 * 	of the CRC a.k.a. CRC32 code in the Images
 */

#include "chunk.h"

using namespace std;

// this function loads the crc
unsigned long Chunk::LoadCRC()
{
	// add the remaining 3 chars of the type and the length of the chunk, to see the crc
	vector<unsigned char>::iterator crcFinder = _typePos + 3 + _length;

	// get size of chunk
	unsigned char charCRCArray[5] = {
		*(crcFinder),
		*(crcFinder + 1),
		*(crcFinder + 2),
		*(crcFinder + 3)
	};

	unsigned long cyclicRedundancyCheck = 0;

	for(int i = 0; i < 4; i++)
	{
		cyclicRedundancyCheck = cyclicRedundancyCheck << 8;
		cyclicRedundancyCheck += charCRCArray[i];
	}

	return cyclicRedundancyCheck;
}

void Chunk::UpdateCRC()
{
	vector<unsigned char>::iterator it = _typePos + 4;
	vector<unsigned char>::iterator dataEnd = _typePos + 3 + _length;
	
	unsigned int dataLen = dataEnd - it;

	//part 1
	unsigned long crc_table[256];
	unsigned long c;
    int n, k;

    //n is the size of the array
    for (n = 0; n < 256; n++)
    {
        c = (unsigned long) n;
        for (k = 0; k < 8; k++)
        {
            //if c != 0 then true
            if (c & 1)
            {
                /*
                * hex: 0xedb88320
                * bin: ‭1110'1101'1011'1000'1000'0011'0010'0000‬
                * dec: ‭3'988'292'384‬
                */
			   // what does this number mean ????
                c = 0xedb88320L ^ (c >> 1);
            }
            else
            {
                c = c >> 1;
            }
            
        }

        crc_table[n] = c;
    }

	//part 2
	unsigned long c = 0xffffffffL;

    for (; it != dataEnd; it++)
    {
        c = crc_table[(c ^ *(it)) & 0xff] ^ (c >> 8);
    }
    
	unsigned long newCRC = c ^ 0xffffffffL;
	cout << "new crc: " << newCRC << endl;
}

