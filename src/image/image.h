/*
 * Author: youngtrashbag
 * Date: 19.03.2020
 * File: image.h
 * Description:
 * 	Header File of Image Class.
 */

#include "../header.h"

class Image
{
	private:
		/* attributes */
		// the filename of the image file
		std::string _fileName;
		Chunk _chunkArray[8];

	public:
		/* functions */

		// constructor
		Image(std::string pFileName);

		Chunk GetChunk(char pType[5]);
		std::string GetFileName();

};

