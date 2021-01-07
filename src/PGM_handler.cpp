#include "PGM_handler.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

PGM_handler::PGM_handler(const unsigned short width, const unsigned short height): m_width(width), m_height(height)
{

}

PGM_handler::~PGM_handler()
{

}

void PGM_handler::create_ASCII_PGM_from_data(vector<vector<float>> data)
{
	float points[m_width][m_height];  // Will contain the values of the MNT image

  // Init points at 0 (black)
  for (int i=0 ; i<m_width ; i++)
  {
    for (int j=0 ; j<m_height ; j++)
    {
      points[i][j] = 0;
    }
  }

  // Set values of points
  for (int i = 0; i<data[0].size() ; i++)
  {
    // Get integer values of data
    int approx_x = floor(data[0][i]);
    int approx_y = floor(data[1][i]);
    int approx_h = floor(data[2][i]);

    // Check if approx_x and approx_y are not out of array points
    if (approx_x < 0) approx_x=0;
    if (approx_y < 0) approx_y=0;
    if (approx_x >= m_width) approx_x = m_width-1;
    if (approx_y >= m_height) approx_y = m_height-1;

    points[approx_x][approx_y] = approx_h; // Set value

  }
  
	auto max_h = floor(*max_element(data[2].begin(), data[2].end())); // Max h value will be white

	ofstream fout("test_PGM.pgm");

	if (!fout.is_open())
  {
     cout << "Can't open output file" << endl;
  }

  fout << "P2\n" << m_width << " " << m_height << "\n" << max_h << "\n";
  cout << "P2\n" << m_width << " " << m_height << "\n" << max_h << "\n";


  for (int i=0 ; i<m_width ; i++)
  {
    for (int j=0 ; j<m_height ; j++)
    {
      fout << points[i][j] << " ";
    }
    fout << "\n";
  }


  fout.close();

}