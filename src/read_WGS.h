#ifndef __READ_WGS__
#define __READ_WGS__

#include <cstdlib>
#include <fstream>
#include <vector>
#include <array>
#include "WGS84toCartesian.hpp"

using namespace std;


class ReadWGS
{
	public:

		ReadWGS(const string filemane);
		~ReadWGS();

		array<vector<float>, 3> read_raw();
		array<vector<float>, 3> project();

	protected:
		const string m_filename;
};
	
	





#endif