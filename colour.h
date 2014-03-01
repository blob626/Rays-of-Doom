#ifndef _COLOUR_H
#define _COLOUR_H

#include <iostream>

class Colour
{
  int red, green, blue;
  int max;

public:
  Colour();
  Colour(int m);
  Colour(int r, int g, int b);
  Colour(int r, int g, int b, int m);

  Colour& operator+=(const Colour &other);
  
  friend std::ostream& operator<<(std::ostream& stream, Colour col);
};

#endif
