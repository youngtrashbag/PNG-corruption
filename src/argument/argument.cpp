/*
 * Author: youngtrashbag
 * Date: 26.03.2020
 * File: argument.cpp
 * Description:
 * 		Code for Argument Parsing Functions.
 */

#include "argument.h"

using namespace std;

ArgProc::ArgProc(int argc, char* argv[])
{
	_help = false;
	_info = false;
	_file = "";
	_output = "";
	_increment = 0;
	_shift = 0;

	for(int argcount = 1; argcount < argc; argcount++)
	{
		//cout << argv[argcount] << endl;	// prints every argument on screen for debugging

		if(strcmp(argv[argcount], "-h") == 0
			|| strcmp(argv[argcount], "--help") == 0
			|| argc == 1)
		{
			_help = true;
		}

		if(strcmp(argv[argcount], "-i") == 0
			|| strcmp(argv[argcount], "--info") == 0)
		{
			_info = true;
		}

		if(strcmp(argv[argcount], "-f") == 0
			|| strcmp(argv[argcount], "--file") == 0)
		{
			if(argcount + 1 <= argc)
				_file = argv[argcount + 1];
		}

		if(strcmp(argv[argcount], "-o") == 0
			|| strcmp(argv[argcount], "--output") == 0)
		{
			if(argcount + 1 <= argc)
				_output = argv[argcount + 1];
		}

		if(strcmp(argv[argcount], "--increment") == 0)
		{
			if(argcount + 1 < argc)
				_increment = atoi(argv[argcount + 1]);
		}

		if(strcmp(argv[argcount], "--shift") == 0)
		{
			if(argcount + 1 < argc)
				_shift = atoi(argv[argcount + 1]);
		}
	}
}

void ArgProc::PrintHelp()
{
	cout << " -h\t--help\t\tDisplay this Dialog" << endl;
	cout << " -i\t--info\t\tDisplay the Information of IDAT Chunk" << endl;
	cout << " -f\t--file <i.png>\tEnter the file you want to Corrupt" << endl;
	cout << " -o\t--out <i.png>\tEnter a name for the Output file" << endl;
	cout << " --increment <number>\tEnter the Amount of Incrementations to the";
	cout << " individual bytes in the file" << endl;
	cout << " --shift <number>\tEnter the Amount of Positions, the bytes should be shifted" << endl;
}

void ArgProc::PrintChunkInfo(Chunk* pChunk)
{
	cout << "Chunk Type:\t\t" << pChunk->GetType() << endl;
	cout << "Chunk Length:\t\t" << pChunk->GetLength() << endl;
	cout << "Chunk CRC:\t\t" << pChunk->GetCRC() << endl;
	printf("Chunk CRC as hex:\t%08x\n", pChunk->GetCRC());

	// testing things
	cout << "sizeof chunk object:\t" << sizeof pChunk << endl;
}

bool ArgProc::GetHelp()
{
	return _help;
}

bool ArgProc::GetInfo()
{
	return _info;
}

string ArgProc::GetFilename()
{
	return _file;
}

string ArgProc::GetOutputFilename()
{
	return _output;
}

int ArgProc::GetIncrement()
{
	//return _increment;
	return 1;
}

int ArgProc::GetShift()
{
	return _shift;
}

