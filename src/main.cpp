#include "read_WGS.h"
#include <cstdlib>
#include <iostream>
#include "PGM_handler.h"

using namespace std;

int main()
{
	ReadWGS *data_reader = new ReadWGS("Guerledan_Feb19_50cm_wgs84.txt", 800);
	PGM_handler *handler = new PGM_handler(10, 3);
	cout << data_reader->get_scaled_dimensions()[1] << endl;
	//handler->create_ASCII_PGM_from_data(data);


	return EXIT_SUCCESS;
}