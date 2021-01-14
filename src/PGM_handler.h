#ifndef __PGM_HANDLER_H__
#define __PGM_HANDLER_H__

#include <vector>


/**
* \class PGM_handler
* \brief Create the PGM image file from the data
* \author Samuel Prouten
*/
class PGM_handler
{
public:
	/**
	* \brief Creates a PGM_handler
	* \param width Width of the image
	* \param height Height of the image
	*/
	PGM_handler(const unsigned short width, const unsigned short heigth);
	~PGM_handler();

	/**
	* \brief Creates a simple PGM image as a test in ASCII
	*/
	void create_simple_image();

	/**
	* \brief Creates a ASCII PGM image of the data
	* \param data Data given to create the image
	*/
	void create_ASCII_PGM_from_data(std::vector<std::vector<float>> data);

	/**
	* \brief Creates a binary PGM image of the data
	* \param data Data given to create the image
	*/
	void create_binary_PGM_from_data(std::vector<std::vector<float>> data);
		

protected:
	/**
	* \brief Width of the image
	*/
	const unsigned short m_width;
	/**
	* \brief Height of the image
	*/
	const unsigned short m_height;
};

#endif