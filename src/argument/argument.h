/*
 * Author: youngtrashbag
 * Date: 26.03.2020
 * File: argument.h
 * Description:
 * 		Header File for argument parsing.
 */

#include "../chunk/chunk.h"

class ArgProc {
	private:
		// ctor private, becuase static
		ArgProc() {};
		static bool _help;
		static bool _info;
		static std::string _file;
		static std::string _output;
		static int _increment;
		static int _shift;

	public:
		static void init(int argc, char* argv[]);
		static bool PrintHelp();
		static void PrintInfo(Chunk pChunk);
		static std::string GetFilename();
		static std::string GetOutputFilename();
		static int GetIncrement();
		static int GetShift();
};

