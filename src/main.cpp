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
	// processing the arguments
	ArgProc ArgumentProcessor = ArgProc(argc, argv);

	if(ArgumentProcessor.GetHelp())
	{
		ArgumentProcessor.PrintHelp();
		return 0;
	}

	if(ArgumentProcessor.GetFilename() == "")
	{
		cout << "You need to Enter a Filename.\n -h for more info" << endl;
		return 0;
	}

	if(ArgumentProcessor.GetOutputFilename() == "")
	{
		cout << "You need to Enter a Output.\n -h for more info" << endl;
		return 0;
	}

	//TODO: do this so it if --increment and --shift is forgotten print that both are forgotten
	if(ArgumentProcessor.GetIncrement() == 0)
	{
		cout << "Please Enter a Value for Incrementation\n -h for more info" << endl;
		return 0;
	}
	else if(ArgumentProcessor.GetShift() == 0 && ArgumentProcessor.GetIncrement() == 0)
	{
		cout << "Please Enter a Value for Shifting\n -h for more info" << endl;
		return 0;
	}

	//create and open filestream as binary
	ifstream imageFile;
	imageFile.open(ArgumentProcessor.GetFilename(), ios::binary);

	if(!imageFile.good())
	{
		imageFile.close();
		
		cout << "The Input File you selected is not valid." << endl;

		return 0;
	}
	

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
	Chunk idatChunk = Chunk(chunkType, imageFile);

	if(ArgumentProcessor.GetInfo())
	{
		ArgumentProcessor.PrintChunkInfo(&idatChunk);
	}

	// displaying info for user what is happening
	cout << "incrementing by: " << ArgumentProcessor.GetIncrement() << endl;
	idatChunk.Increment(ArgumentProcessor.GetIncrement());

	imageFile.close();

	ofstream newImage;
	newImage.open(ArgumentProcessor.GetOutputFilename(), ios::binary);

	//copy contents from vector to file
	copy(idatChunk.GetBufferBeg(), idatChunk.GetBufferEnd(), ostreambuf_iterator<char>(newImage));

	newImage.close();

	return 0;
}

