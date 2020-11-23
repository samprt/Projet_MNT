#ifndef __READ_WGS__
#define __READ_WGS__

#include <cstdlib>
#include <fstream>
#include <vector>
#include "WGS84toCartesian.hpp"

using namespace std;


class ReadWGS
{
	public:

		ReadWGS(const string filemane);
		~ReadWGS();

		vector<vector<float>> read_raw();
		vector<vector<float>> project();

	protected:
		const string m_filename;
};
	
	





#endif