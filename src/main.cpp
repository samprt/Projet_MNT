#include "read_WGS.h"
#include <cstdlib>
#include "PGM_handler.h"

using namespace std;

int main()
{
	ReadWGS *data_reader = new ReadWGS("test_data_2.txt");
	PGM_handler *handler = new PGM_handler(10, 3);
	auto data = data_reader->read_raw();
	data_reader->project();
	handler->create_ASCII_PGM_from_data(data);


	return EXIT_SUCCESS;
}