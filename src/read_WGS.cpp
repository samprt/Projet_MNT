#include "read_WGS.h"
#include <fstream>
#include <iostream>

using namespace std;

ReadWGS::ReadWGS(const string filename) : m_filename(filename)
{

}

ReadWGS::~ReadWGS()
{

}

vector<vector<float>> ReadWGS::read_raw()
{
	ifstream ifst(m_filename);
	vector<vector<float>> v;
	vector<float> t;
	char str[500];
	const char *space = " ";

	while (true)
	{
		if(!ifst.getline(str, 500, *space)) // Get longitude data as string and tests if the string is valid (not at the end of the file)
		{
			break; // Stiops reading the data
		}
		float longitude = stof(str); // Convert longitude data to float
		
		ifst.getline(str, 500, *space);// Get latitude data as string
		float latitude = stof(str); // Convert latitude data to float
		
		ifst.getline(str, 500);// Get height data as string
		float h = stof(str); // Convert height data to float

		t = {longitude, latitude, h};
		v.push_back(t);
	}

	return v;
}

vector<vector<float>> ReadWGS::project()
{
	vector<vector<float>> raw_data;
	raw_data = read_raw();
	vector<array<float, 3>> projected_data;

	for (int n=0 ; n<raw_data.size() ; n++)
	{
		array<double, 2> cartesianPosition = wgs84::toCartesian({raw_data[n][0], raw_data[n][1]}/*{52.248091, 10.57417} /* reference position */, {raw_data[n][0], raw_data[n][1]} /* position to be converted */);
		array<float, 3> t = {cartesianPosition[0], cartesianPosition[1], raw_data[n][2]};
		projected_data.push_back(t);

	}
	cout << projected_data[0][0] << " " << projected_data[0][1] << " " << projected_data[0][2] << endl;
}