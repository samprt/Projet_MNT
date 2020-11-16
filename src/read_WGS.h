#ifndef __READ_WGS__
#define __READ_WGS__

#include <cstdlib>
#include <fstream>
#include <vector>


class ReadWGS
{
	public:

		ReadWGS(const std::string filemane);
		~ReadWGS();

		std::vector<std::vector<float>> read_raw();

	protected:
		const std::string m_filename; 
};
	
	





#endif