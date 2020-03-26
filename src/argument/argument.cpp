/*
 * Author: youngtrashbag
 * Date: 26.03.2020
 * File: argument.cpp
 * Description:
 * 		Code for Argument Parsing Functions.
 */

#include "argument.h"

using namespace std;

void ProcessArgs(int argc, char* argv[])
{
	bool help = false, info = false;
	string file = "", output = "";
	int increment = 0, shift = 0;

	for(int argcount = 1; argcount < argc; argcount++)
	{
		cout << argv[argcount] << endl;

		if(strcmp(argv[argcount], "-h") == 0
			|| strcmp(argv[argcount], "--help") == 0)
		{
			help = true;
		}

		if(strcmp(argv[argcount], "-i") == 0
			|| strcmp(argv[argcount], "--info") == 0)
		{
			info = true;
		}

		if(strcmp(argv[argcount], "-f") == 0
			|| strcmp(argv[argcount], "--file") == 0)
		{
			if(argcount + 1 <= argc)
				file = argv[argcount + 1];
		}

		if(strcmp(argv[argcount], "-o") == 0
			|| strcmp(argv[argcount], "--out") == 0)
		{
			if(argcount + 1 <= argc)
				output = argv[argcount + 1];
		}

		if(strcmp(argv[argcount], "--increment") == 0)
		{
			if(argcount + 1 < argc)
				increment = atoi(argv[argcount + 1]);
		}

		if(strcmp(argv[argcount], "--shift") == 0)
		{
			if(argcount + 1 < argc)
				shift = atoi(argv[argcount + 1]);
		}
	}

	if(help)
	{
		// TODO: display help dialog
		cout << " -h\t--help\t\tDisplay this Dialog" << endl;
		cout << " -i\t--info\t\tDisplay the Information of IDAT Chunk" << endl;
		cout << " -f\t--file <i.png>\tEnter the file you want to Corrupt" << endl;
		cout << " -o\t--out <i.png>\tEnter a name for the Output file" << endl;
		cout << " --increment <number>\tEnter the Amount of Incrementations to the";
		cout << " individual bytes in the file" << endl;
		cout << " --shift <number>\tEnter the Amount of Positions, the bytes should be shifted" << endl;
	}
	else if(info)
	{
		//display the file info later in program
	}
	else if(file != "" && output != "")
	{
		// output filename is not empty
		cout << "file: " << file << endl;
		cout << "output: " << output << endl;
	}

	// increment is preferred to shift
	if(increment != 0 && !help)
	{
		// return increment
		cout << "increment: " << increment << endl;
	}
	else if(shift != 0 && !help)
	{
		// return shift
		cout << "shift: " << shift << endl;
	}
}

