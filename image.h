#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
#include <vector>
#include "colour.h"

class Image
{
  bool binary;
  int width, height;
  int maxValue;
  std::vector<std::vector<Colour> > image;
  
 public:
  Image();
  Image(int w, int h);
  Image(int w, int h, int m);

  void setBinary(bool bin);

  friend std::ostream& operator<<(std::ostream& stream, Image img);

private:
  void initImage();
  
};

#endif
