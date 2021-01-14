#ifndef __READ_WGS__
#define __READ_WGS__

#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

/**
* \class ReadWGS
* \brief This class is created to read the data from a text file and store it in a vector "data".
* \author Samuel Prouten
*/
class ReadWGS
{
	public:
		/**
		* \brief Creates a data file reader
		* \param filename The name of the text file containing the data
		* \param width The width of the image to create
		*/
		ReadWGS(const string filemane, const int width);
		~ReadWGS();

		/**
		* \brief Reads the raw data from the file.
		*/
		vector<vector<float>> read_raw();
		/**
		* \brief Reads the raw data from the file and project it in the (x,y) plane.
		*/
		vector<vector<float>> read_and_project();
		/**
		* \brief Rescales the projected data to respect the parameter width.
		*/
		vector<vector<float>> rescale_data();
		
		/**
		* \brief Contains the raw data, the projected data or the rescaled data.
		*/
		vector<vector<float>> data;
		/**
		* \brief Maximum projected data along the x axis
		*/
		float max_data_x;
		/**
		* \brief Minimum projected data along the x axis
		*/
		float min_data_x;
		/**
		* \brief Maximum projected data along the y axis
		*/
		float max_data_y;
		/**
		* \brief Minimum projected data along the y axis
		*/
		float min_data_y;
		/**
		* \brief max_data_x - min_data_x
		*/
		float m_data_width;
		/**
		* \brief max_data_y - min_data_y
		*/
		float m_data_height;
		/**
		* \brief width of the image we want to create
		*/
		const int m_scaled_width;
		/**
		* \brief Calculated height of the image
		*/
		int m_scaled_height;

	protected:
		/**
		* \brief Name of the data file
		*/
		const string m_filename;
		
};

#endif