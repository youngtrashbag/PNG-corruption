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
	bool help = false;
	string output = "";
	int increment = 0, shift = 0;

	for(int argcount = 1; argcount < argc; argcount++)
	{
		cout << argv[argcount] << endl;

		if(argv[argcount] == "-h"
			|| argv[argcount] == "--help")
		{
			help = true;
		}

		if(argv[argcount] == "-o"
			|| argv[argcount] == "--output")
		{
			if(argcount + 1 <= argc)
				output = argv[argcount + 1];
		}

		if (argv[argcount] == "--increment")
		{
			if(argcount + 1 <= argc)
				increment = argv[argcount + 1];
		}

		if (argv[argcount] == "--shift")
		{
			if(argcount + 1 <= argc)
				shift = argv[argcount + 1];
		}
	}

	if(help)
	{
		// TODO: display help dialog
	}
	else if(output != "")
	{
		// output filename is not empty
	}

	// increment is preferred to shift
	if(increment != 0)
	{
		// return increment
	}
	else if(shift != 0)
	{
		// return shift
	}
}

