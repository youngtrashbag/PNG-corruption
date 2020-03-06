/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: increment-func.cpp
 * Description:
 * 	Functions for the Increment Process.
 */

#include "../header.h"

// increment the value of every char in the buffer
void incrementBuffer(vector<unsigned char> &buffer, unsigned int incrementation)
{
	vector<unsigned char>::iterator it = buffer.begin();

	for(; it != buffer.end(); it++)
	{
		*it += incrementation;
	}
}
