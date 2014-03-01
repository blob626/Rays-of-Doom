#include "image.h"
#include <iostream>
#include <vector>
#include <string>

Image::Image()
  : binary(false), width(0), height(0), maxValue(0)
{}

Image::Image(int w, int h)
  : binary(false), width(w), height(h), maxValue(255)
{
  initImage();
}

Image::Image(int w, int h, int m)
  : binary(false), width(w), height(h), maxValue(m)
{
  initImage();
}

void Image::initImage()
{
  for(int h = 0; h < height; ++h)
    {
      std::vector<Colour> row;
      data.push_back(row);
      for(int w = 0; w < width; ++w)
	{
	  Colour col(maxValue);
	  data[h].push_back(col);
	}
    }
}

void Image::setBinary(bool bin)
{
  binary = bin;
}

std::ostream& operator<<(std::ostream& stream, Image img)
{
  std::string magic = img.binary ? "P6" : "P3";
  stream << magic << std::endl;
  stream << img.width << " " << img.height << std::endl;
  stream << img.maxValue << std::endl;

  for(int h = 0; h < img.height; ++h)
    {
      for(int w = 0; w < img.width; ++w)
	{
	  stream << img.data[h][w] << "  ";
	}
      stream << std::endl;
    }
  return stream;
}
