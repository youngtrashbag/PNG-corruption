/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.cpp
 */

#include "header.h"
#include "chunk/chunk.h"
#include "argument/argument.h"

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

	// processing the arguments
	ArgProc ArgumentProcessor = ArgProc(argc, argv);

	if(ArgumentProcessor.GetHelp())
	{
		ArgumentProcessor.PrintHelp();
		exit(101);
	}

	if(ArgumentProcessor.GetFilename() == "")
	{
		cout << "You need to Enter a Filename.\n -h for more info" << endl;
		exit(102);
	}

	if(ArgumentProcessor.GetOutputFilename() == "")
	{
		cout << "You need to Enter a Output.\n -h for more info" << endl;
		exit(103);
	}

	//TODO: do this so it if --increment and --shift is forgotten print that both are forgotten
	if(ArgumentProcessor.GetIncrement() == 0)
	{
		cout << "Please Enter a Value for Incrementation\n -h for more info" << endl;
		exit(104);
	}
	else if(ArgumentProcessor.GetShift() == 0 && ArgumentProcessor.GetIncrement() == 0)
	{
		cout << "Please Enter a Value for Shifting\n -h for more info" << endl;
		exit(105);
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

	if(ArgumentProcessor.GetInfo())
	{
		ArgumentProcessor.PrintChunkInfo(idatChunk);
		exit(106);
	}

	idatChunk->Increment(0);

	imageFile.close();

	ofstream newImage;
	newImage.open(ArgumentProcessor.GetOutputFilename(), ios::binary);

	//copy contents from vector to file
	copy(idatChunk->GetBufferBeg(), idatChunk->GetBufferEnd(), ostreambuf_iterator<char>(newImage));

	newImage.close();

	return 0;
}

