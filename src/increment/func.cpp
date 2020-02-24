/*
 * Author: youngtrashbag
 * Date: 20.02.2020
 * File: increment.cpp
 */

#include "increment.h"

using namespace std;

void incrementBuffer(vector<unsigned char> &imgVector, unsigned int incrementation)
{
	vector<unsigned char>::iterator it = imgVector.begin();

	//1. skip header
	//i know that png header is 4bytes and 1 unsigned char is 1byte; therefore
	it += 4;

	//2. increment other chars
	for(; it != imgVector.end(); it++)
	{
		if(*it >= 32 && *it < 126)
		{
			*it += incrementation;
		}
	}
}

