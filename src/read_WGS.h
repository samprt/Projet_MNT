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

		vector<vector<float>> read_raw();
		vector<vector<float>> read_and_project();
		vector<vector<float>> rescale_data();
		

		vector<vector<float>> data;
		float max_data_x;
		float min_data_x;
		float max_data_y;
		float min_data_y;
		float m_data_width;
		float m_data_height;
		const int m_scaled_width;
		int m_scaled_height;

		//array<array<float, m_scaled_height>, m_scaled_width> create_data_matrix();


	protected:
		const string m_filename;
		
};
	
	





#endif