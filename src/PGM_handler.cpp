#include "PGM_handler.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

PGM_handler::PGM_handler(const unsigned short width, const unsigned short height): m_width(width), m_height(height)
{

}

PGM_handler::~PGM_handler()
{

}

void PGM_handler::create_simple_image()
{
  ofstream fout("test_PGM.pgm");

  if (!fout.is_open())
  {
     cout << "Can't open output file" << endl;
  }

  fout << "P2\n" << 5 << " " << 5 << "\n" << 25 << "\n";

  int t = 0;
  for (int i=0 ; i<5 ; i++)
  {
    for (int j=0 ; j<5 ; j++)
    {
      fout << t << " ";
      t++; 
    }
    fout << "\n";
  }
  fout.close();
}

int NumDigits(int x)
{
  int length = 1;
  while ( x /= 10 )
    length++;
  return length;
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
    int approx_x = int(data[0][i]);
    int approx_y = int(data[1][i]);
    int approx_h = int(data[2][i]);

    // Check if approx_x and approx_y are not out of array points
    if (approx_x < 0) approx_x=0;
    if (approx_y < 0) approx_y=0;
    if (approx_x >= m_width) approx_x = m_width-1;
    if (approx_y >= m_height) approx_y = m_height-1;

    points[approx_x][approx_y] = approx_h; // Set value

  }
  
	// Get max height value for PGM file header
  auto max_h = floor(*max_element(data[2].begin(), data[2].end())); // Max h value will be white

	// Open file and write header
  ofstream fout("Guerledan_PGM_ASCII.pgm");
  if (!fout.is_open())
  {
     cout << "Can't open output file" << endl;
  }
  fout << "P2\n" << m_width << " " << m_height << "\n" << max_h << "\n";

  // Write file : if the number of characters on the line exeeds 70 -> new line
  int nb_characters_on_line = 0;
  int t;
  for (int i=0 ; i<m_width ; i++)
  {
    for (int j=0 ; j<m_height ; j++)
    {
      fout << points[i][j];
      t = NumDigits(points[i][j]);
      nb_characters_on_line += t;

      // Add space or new line after character
      if (nb_characters_on_line == 70)
      {
        fout << "\n";
        nb_characters_on_line = 0;
      }
      else
      {
        fout << " ";
        nb_characters_on_line++;
      }
      
    }
  }
  fout.close();
}

void PGM_handler::create_binary_PGM_from_data(vector<vector<float>> data)
{
  bitset<8> points[m_width][m_height];  // Will contain the values of the MNT image

  bitset<8> zero(0);
  // Init points at 0 (black)
  for (int i=0 ; i<m_width ; i++)
  {
    for (int j=0 ; j<m_height ; j++)
    {
      points[i][j] = zero;
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

    bitset<8> bin(approx_h);
    points[approx_x][approx_y] = bin; // Set value

  }
  
  auto max_h = floor(*max_element(data[2].begin(), data[2].end())); // Max h value will be white

  ofstream fout("Guerledan_PGM_binary.pgm");

  if (!fout.is_open())
  {
     cout << "Can't open output file" << endl;
  }

  fout << "P5\n" << m_width << " " << m_height << "\n" << max_h << "\n";

  for (int i=0 ; i<m_width ; i++)
  {
    for (int j=0 ; j<m_height ; j++)
    {
      fout << points[i][j];
    }
    fout << "\n";
  }
  fout.close();
}
