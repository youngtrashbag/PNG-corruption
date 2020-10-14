/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: func.cpp
 */

#include "header.h"

using namespace std;

// check if file exists, if yes return the filename, if no return the filename in docs
string validFilename(string cmdParam)
{
	string filename = string(cmdParam);
	ifstream file(filename);

	if(file.good())
	{
		file.close();
		return filename;
	}
	else
	{
		file.close();
		// docs/sample.png
		return IMAGE_1;
	}
}

unsigned int fileSize(fstream &file)
{
	file.seekg(0, ios::end);
	unsigned int size = file.tellg();
	file.seekg(0, ios::beg);

	return size;
}

