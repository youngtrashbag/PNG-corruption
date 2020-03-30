/*
 * Author: youngtrashbag
 * Date: 26.03.2020
 * File: argument.h
 * Description:
 * 		Header File for argument parsing.
 */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "../chunk/chunk.h"

class ArgProc {
	private:
		// ctor private, becuase static
		bool _help;
		bool _info;
		std::string _file;
		std::string _output;
		int _increment;
		int _shift;

	public:
		//static ArgProc init(int argc, char* argv[]);
		ArgProc(int argc, char* argv[]);
		void PrintHelp();
		void PrintChunkInfo(Chunk* pChunk);
		std::string GetFilename();
		bool GetHelp();
		bool GetInfo();
		std::string GetOutputFilename();
		int GetIncrement();
		int GetShift();
};

