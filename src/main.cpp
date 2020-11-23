#include "read_WGS.h"
#include <cstdlib>

using namespace std;

int main()
{
	ReadWGS *data_reader = new ReadWGS("test_data.txt");
	data_reader->read_raw();
	data_reader->project();


	return EXIT_SUCCESS;
}