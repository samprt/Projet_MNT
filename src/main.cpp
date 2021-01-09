#include "read_WGS.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
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



	return EXIT_SUCCESS;
}