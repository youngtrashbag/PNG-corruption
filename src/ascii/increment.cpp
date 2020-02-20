/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.cpp
 */

#include "increment.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = validFilename(argv[1]);

	//create and open filestream as binary
	ifstream imageFile;
	imageFile.open(filename, ios::binary);

	ofstream newImage;
	newImage.open("inc-" + filename, ios::binary);

	//contains the opened image
	vector<unsigned char> buffer(istreambuf_iterator<char>(imageFile), {});
	imageFile.close();

	copy(buffer.begin(), buffer.end(), ostreambuf_iterator<char>(newImage));

	newImage.close();

	return 0;
}

