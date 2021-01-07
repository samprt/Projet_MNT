#ifndef __PGM_HANDLER_H__
#define __PGM_HANDLER_H__

#include <vector>



class PGM_handler
{
public:
		PGM_handler(const unsigned short width, const unsigned short heigth);
		~PGM_handler();
		void create_ASCII_PGM_from_data(std::vector<std::vector<float>> data);

protected:
		const unsigned short m_width;
		const unsigned short m_height;
};





#endif