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
	//save buffer in image
	cout << "Writing changes to new file: " << newFilename << endl;
	copy(buffer.begin(), buffer.end(), ostreambuf_iterator<char>(newImage));

	char chunkType[] = {'I', 'D', 'A', 'T', '\0'};
	int test = GetChunkBuffer(imageFile, chunkType);
	cout << "IDAT CHUNK IS: " << test << " bytes in length i think." << endl;

	newImage.close();*/

	vector<unsigned char> imageBuffer(istreambuf_iterator<char>(imageFile), {});

	char chunkType[] = {'I', 'D', 'A', 'T', '\0'};
	Chunk* idatChunk = new Chunk(chunkType, imageBuffer);

	//idatChunk->Load(imageFile);
	imageFile.close();

	return 0;
}

