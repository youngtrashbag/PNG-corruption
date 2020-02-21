/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: func.cpp
 */

#include "header.h"

using namespace std;

// check if file exists, if yes return the filename, if no return the filename in docs
string validFilename(char* argv[])
{
	ifstream file(argv[1]);

	if(file.good())
	{
		file.close();
		return argv[1];
	}
	else
	{
		file.close();
		// docs/sample.png
		return IMAGE_1;
	}
}

void saveImage(fstream &file)
{
	//save de iamge
}

