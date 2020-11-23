#include "PGM_handler.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

PGM_handler::PGM_handler(const unsigned short width, const unsigned short height): m_width(width), m_height(height)
{

}

PGM_handler::~PGM_handler()
{

}

void PGM_handler::create_ASCII_PGM_from_data(array<vector<float>, 3> data)
{
	auto max_x = *max_element(data[0].begin(), data[0].end());
	auto max_y = *max_element(data[1].begin(), data[1].end());
	auto max_h = *max_element(data[2].begin(), data[2].end());

	ofstream fout("test_PGM.pgm");

	if (!fout.is_open())
  {
     cout << "Can't open output file" << endl;
  }

  fout << "P2\n" << m_width << " " << m_height << "\n" << max_h << "\n";

  int i = 0;

  for (int y=0 ; y<max_y ; y++)
  {
  	for (int x=0 ; x<max_x ; x++)
  	{
  		fout << data[2][i] << " ";
  		i++;
  	}

  	fout <<"\n";
  }

  fout.close();

}