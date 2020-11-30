#include "read_WGS.h"
#include <cstdlib>
#include <iostream>
#include "PGM_handler.h"

using namespace std;

int main(int argc, char *argv[])
{
	ReadWGS *data_reader = new ReadWGS(argv[1], stoi(argv[2]));
	PGM_handler *handler = new PGM_handler(10, 3);
	
	data_reader->rearange_data();
	cout << data_reader->data[0][0] << endl;
	//handler->create_ASCII_PGM_from_data(data);


	return EXIT_SUCCESS;
}