#include "read_WGS.h"
#include <iostream>
#include <algorithm>
#include "WGS84toCartesian.hpp"


using namespace std;

ReadWGS::ReadWGS(const string filename, const int width) : m_filename(filename), m_width(width)
{
	data = read_and_project();
	max_data_x = *max_element(data[0].begin(), data[0].end());
	min_data_x = *min_element(data[0].begin(), data[0].end());
	max_data_y = *max_element(data[1].begin(), data[1].end());
	min_data_y = *min_element(data[1].begin(), data[1].end());
}

ReadWGS::~ReadWGS()
{

}

array<vector<float>, 3> ReadWGS::read_raw()
{
	ifstream ifst(m_filename);
	array<vector<float>, 3> data;
	vector<float> lat;
	vector<float> lon;
	vector<float> h;
	char str[500];
	const char *space = " ";

	while (true)
	{
		if(!ifst.getline(str, 500, *space)) // Get latitude data as string and tests if the string is valid (not at the end of the file)
		{
			break; // Stops reading the data
		}
		float latitude = stof(str); // Convert latitude data to float
		lat.push_back(latitude);
		
		ifst.getline(str, 500, *space);// Get longitude data as string
		float longitude = stof(str); // Convert longitude data to float
		lon.push_back(longitude);
		
		ifst.getline(str, 500);// Get height data as string
		float height = stof(str); // Convert height data to float
		h.push_back(height);
	}

	data = {lat, lon, h};

	return data;
}

array<vector<float>, 3> ReadWGS::read_and_project()
{
	array<vector<float>, 3> raw_data;
	raw_data = read_raw();

	vector<float> x;
	vector<float> y;

	auto max_lat = *max_element(raw_data[0].begin(), raw_data[0].end());
	auto min_lon = *min_element(raw_data[1].begin(), raw_data[1].end());

	for (int n=0 ; n<raw_data[0].size() ; n++)
	{
		array<double, 2> cartesianPosition = wgs84::toCartesian({max_lat, min_lon} /* reference position */, {raw_data[0][n], raw_data[1][n]} /* position to be converted */);
		x.push_back(cartesianPosition[0]);
		y.push_back(cartesianPosition[1]);

	}
	array<vector<float>, 3> projected_data;
	projected_data[0] = x;
	projected_data[1] = y;
	projected_data[2] = raw_data[2];

	return projected_data;
}

array<float, 2> ReadWGS::get_scaled_dimensions()
{
	int width = max_data_x - min_data_x;
	int height = max_data_y - min_data_y;

	int scaled_width = m_width;
	int scaled_height = (height * m_width) / width;

	return array<float, 2> {scaled_width, scaled_height}; 
}

