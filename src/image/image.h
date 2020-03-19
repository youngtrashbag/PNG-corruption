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
		// the filestream
		std::filestream &_fileStream;
		// the filename of the image file
		std::string _fileName;
		std::vector<Chunk> chunks;

	public:
		/* functions */

		// constructor
		Image(std::string pFilename, std::ifstream &pFile);

		Chunk GetChunk(char pType[5]);
		std::string GetFileName();

};

