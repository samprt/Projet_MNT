#include "read_WGS.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "PGM_handler.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "\nPlease specify the data file and width of image to create.\n" << endl;
		return EXIT_FAILURE;
	}
	ReadWGS data_reader(argv[1], stoi(argv[2]));
	auto data = data_reader.data;
	ofstream f("data.txt");
	for (int i = 0 ; i < data[0].size() ; i++)
	{
		f << data[0][i] << " " << data[1][i] << " " << data[2][i] << "\n";
	}

	PGM_handler handler(data_reader.m_scaled_width, data_reader.m_scaled_height);
	
	handler.create_ASCII_PGM_from_data(data);


	return EXIT_SUCCESS;
}