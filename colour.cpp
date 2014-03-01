#include "colour.h"
#include <iostream>

Colour::Colour()
  : red(0), green(0), blue(0), max(255)
{}

Colour::Colour(int m)
  : red(0), green(0), blue(0), max(m)
{}

Colour::Colour(int r, int g, int b)
  : red(r), green(g), blue(b)
{}

Colour::Colour(int r, int g, int b, int m)
{
  red = r < m ? r : m;
  green = g < m ? g : m;
  blue = b < m ? b : m;
  max = m;
}

Colour& Colour::operator+=(const Colour &other)
{
  int temp;

  if(red < max)
    {
      temp = red + other.red;
      red = temp < max ? temp : max;
    }

  if(green < max)
    {
      temp = green + other.green;
      green = temp < max ? temp : max;
    }
  
  if(blue < max)
    {
      temp = blue + other.blue;
      blue = temp < max ? temp : max;
    }
  
  return *this;
}

std::ostream& operator<<(std::ostream& stream, Colour col)
{
  stream << col.red << " " << col.green << " " << col.blue;
  return stream;
}
