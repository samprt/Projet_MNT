#include "read_WGS.h"
#include <fstream>
#include <iostream>

ReadWGS::ReadWGS(const std::string filename) : m_filename(filename)
{

}

ReadWGS::~ReadWGS()
{

}

std::vector<std::vector<float>> ReadWGS::read_raw()
{
	std::ifstream ifst(m_filename);
	std::vector<std::vector<float>> v;
	std::vector<float> t;
	char str[500];
	const char *space = " ";

	while (true)
	{
		if(!ifst.getline(str, 500, *space)) // Get longitude data as string and tests if the string is valid (not at the end of the file)
		{
			break; // Stiops reading the data
		}
		float longitude = std::stof(str); // Convert longitude data to float
		
		ifst.getline(str, 500, *space);// Get latitude data as string
		float latitude = std::stof(str); // Convert latitude data to float
		
		ifst.getline(str, 500);// Get height data as string
		float h = std::stof(str); // Convert height data to float

		t = {longitude, latitude, h};
		v.push_back(t);
	}

	return v;
}

std::vector<std::vector<float>> ReadWGS::project()
{
	std::vector<std::vector<float>> raw_data;
	raw_data = read_raw();


}