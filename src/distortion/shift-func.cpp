/*
 * Author: youngtrashbag
 * Date: 06.03.2020
 * File: shift-func.cpp
 * Description:
 * 	House Functions for Shift Process
 */

#include "../header.h"

// shift position of the chars
void shiftBuffer(vector<unsigned char> &buffer, unsigned int amount)
{
	vector<unsigned char>::iterator it = buffer.end();

	//iterate this backwards

	for(; it != buffer.begin(); it--)
	{
		*(it) = incrementation;
	}
}
