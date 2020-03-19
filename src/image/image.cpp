/*
 * Author: youngtrashbag
 * Date: 19.03.2020
 * File: image.cpp
 * Description:
 * 	Code File Containting Functions of Image Class.
 */

using namespace std;

Image::Image(string pFilename, ifstream &pFile);
{
	_fileStream = pFile;
	_fileName = pFileName;
}

Chunk Image::GetChunk(char pType[5])
{
	vector<Chunk>::iterator it = _chunks.begin();
	for(; it != _chunks.end(); it++)
	{
		if(*it.GetType() == pType)
		{
			return *it;
		}
	}

	// in case there was no match
	return Chunk("IDAT", _fileStream);
}

std::string Image::GetFileName()
{
	return _fileName;
}

