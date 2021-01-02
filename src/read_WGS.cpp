#include "read_WGS.h"
#include <iostream>
#include <algorithm>
#include "WGS84toCartesian.hpp"


using namespace std;

/**
* This function creates the file reader that will read from file "filename"
* We must also give the width of the final MNT image
*/
ReadWGS::ReadWGS(const string filename, const int width) : m_filename(filename), m_scaled_width(width)
{
	data = read_and_project();
	max_data_x = *max_element(data[0].begin(), data[0].end());
	min_data_x = *min_element(data[0].begin(), data[0].end());
	max_data_y = *max_element(data[1].begin(), data[1].end());
	min_data_y = *min_element(data[1].begin(), data[1].end());

	m_data_width = max_data_x - min_data_x;
	m_data_height = max_data_y - min_data_y;

	m_scaled_height = (m_data_height * m_scaled_width) / m_data_width;

}

ReadWGS::~ReadWGS()
{

}

/**
* Reads the raw data from the file and stores it in a vector of shape (3, length(file))
*/
vector<vector<float>> ReadWGS::read_raw()
{
	ifstream ifst(m_filename);
	vector<vector<float>> data;
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

	data.push_back(lat);
	data.push_back(lon);
	data.push_back(h);

	return data;
}

/**
* Reads the raw daa from file and then projects it from WGS coordinates to Cartesian coordinates with the most north-western point being (0, 0)
*/
vector<vector<float>> ReadWGS::read_and_project()
{
	vector<vector<float>> raw_data;
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
	vector<vector<float>> projected_data;
	projected_data.push_back(x);
	projected_data.push_back(y);
	projected_data.push_back(raw_data[2]);


	ofstream f("projected_data.txt");
	for (int i = 0 ; i < projected_data[0].size() ; i++)
	{
		f << projected_data[0][i] << " " << projected_data[1][i] << " " << projected_data[2][i] << "\n";
	}

	return projected_data;
}

/**
* A simple function that transposes a 2D vector
*/
vector<vector<float>> transpose(vector<vector<float>>& vect)
{
	vector<vector<float>> transposed(vect[0].size(), vector<float>());
	for (size_t i = 0 ; i < vect.size() ; i++)
		for (size_t j = 0 ; j < vect[0].size() ; j++)
			transposed[j].push_back(vect[i][j]);
	return transposed;
}
/**
* A function that reaaranges the data along the x axis
*/
vector<vector<float>> ReadWGS::rearange_data()
{
	data = transpose(data);
	sort(data.begin(), data.end(), [](const vector<float>& lhs, const vector<float>& rhs){return lhs[0] < rhs[0];});
	data = transpose(data);
	return data;
}



