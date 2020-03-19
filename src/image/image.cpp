/*
 * Author: youngtrashbag
 * Date: 19.03.2020
 * File: image.cpp
 * Description:
 * 	Code File Containting Functions of Image Class.
 */

Image::Image(std::string pFileName)
{
	_fileName = pFileName;

	for(int ci = 0; ci < (sizeof(_chunkArray) / sizeof(_chunkArray[0])); ci++)
	{
		_chunkArray[ci] = Chunk("IDAT");
	}
}

Chunk Image::GetChunk(char pType[5])
{
	for(int i = 0; i < (sizeof(_chunkArray) / sizeof(_chunkArray[0])); i++)
	{
		if(_chunkArray[i].GetType() == pType)
		{
			return _chunkArray[i];
		}
	}

	// in case there was no match
	return Chunk("IHDR");
}

std::string Image::GetFileName()
{
}

