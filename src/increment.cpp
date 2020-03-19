/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.cpp
 */

#include "header.h"
#include "chunk/chunk.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = IMAGE_1;
	string newFilename;

	if(argc > 1)
	{
		ifstream file(argv[1]);

		if(file.good())
		{
			filename = argv[1];
		}

		file.close();
	}

	//create and open filestream as binary
	ifstream imageFile;
	imageFile.open(filename, ios::binary);

	/*cout << "Opening file: " << filename << endl;

	ofstream newImage;
	newFilename = "inc-" + filename;
	newImage.open(newFilename, ios::binary);

	//contains the newly opened image
	vector<unsigned char> buffer(istreambuf_iterator<char>(imageFile), {});
	imageFile.close();

	//do things with buffer
	//incrementBuffer(buffer, DEFAULT_INCREMENT_AMOUNT);

	newImage.close();*/

	char chunkType[] = {'I', 'D', 'A', 'T', '\0'};
	Chunk* idatChunk = new Chunk(chunkType, imageFile);

	GetChunkInfo(*idatChunk);

	idatChunk->Increment(1);

	imageFile.close();

	ofstream newImage;
	newFilename = "inc-" + filename;
	newImage.open(newFilename, ios::binary);

	//copy contents from vector to file
	copy(idatChunk->GetBufferBeg(), idatChunk->GetBufferEnd(), ostreambuf_iterator<char>(newImage));

	newImage.close();

	return 0;
}

