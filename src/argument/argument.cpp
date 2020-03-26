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
	for(unsigned char argcount = 1; argcount < argc; argcount++)
	{
		cout << argv[argcount] << endl;
	}
}

