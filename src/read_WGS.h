#ifndef __READ_WGS__
#define __READ_WGS__

#include <cstdlib>
#include <fstream>
#include <vector>
#include <array>

using namespace std;


class ReadWGS
{
	public:

		ReadWGS(const string filemane, const int width);
		~ReadWGS();

		array<vector<float>, 3> read_raw();
		array<vector<float>, 3> read_and_project();
		array<float, 2> get_scaled_dimensions();
		array<vector<float>, 3> rearange_data();

		array<vector<float>, 3> data;
		float max_data_x;
		float min_data_x;
		float max_data_y;
		float min_data_y;

	protected:
		const string m_filename;
		const int m_width;
};
	
	





#endif