#include "read_WGS.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "PGM_handler.h"

using namespace std;


int main(int argc, char *argv[])
{
	// Check if the inputs are valid
	if (argc != 3)
	{
		cout << "\nPlease specify the data file and width of image to create.\n" << endl;
		return EXIT_FAILURE;
	}

	// Create the data reader object
	ReadWGS data_reader(argv[1], stoi(argv[2]));

	// Extract data
	auto data = data_reader.data;
	
	// Create the PGM handler object
	PGM_handler handler(data_reader.m_scaled_width, data_reader.m_scaled_height);
	
	// Create PGM images (ASCII and binary)
	handler.create_simple_image();
	handler.create_ASCII_PGM_from_data(data);
	handler.create_binary_PGM_from_data(data);

	/*
	// Tests
	PGM_handler test_handler(5, 5);
	vector<float> x_v;
	vector<float> y_v;
	vector<float> h_v;
	vector<vector<float>> test_data;
	for (int x = 0 ; x<5 ; x++)
	{
		for (int y = 0 ; y<5 ; y++)
		{
			x_v.push_back(x);
			y_v.push_back(y);
			if (x==0 | x==4 | y==0 | y==4)
			{
				h_v.push_back(1);
			}
			else
			{
				h_v.push_back(0);
			}
		}
	}
	test_data.push_back(x_v);
	test_data.push_back(y_v);
	test_data.push_back(h_v);
	test_handler.create_ASCII_PGM_from_data(test_data);
	*/


	return EXIT_SUCCESS;
}