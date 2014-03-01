#include <iostream>
#include <fstream>
#include "vector3.h"
#include "image.h"
#include "camera.h"
#include "ray.h"

int main(int argc, char* argv[])
{
  Vector3 origin;
  Vector3 a(1, 0, 0);
  Vector3 b(0, 1, 0);
  Vector3 c(0, 0, 1);

  std::cout << a.cross(b).normal().magnitude() << std::endl;

  int width = 100;
  int height = 100;

  Image image(width, height, 255);
  Camera camera(width, height);

  Vector3 sphereCenter(0, 50, -50);
  double radius = 10;
  
  for(int row = 0; row < height; ++row)
    {
      for(int col = 0; col < width; ++col)
	{
	  double inter=camera.getRay(row,col).intersect(sphereCenter,radius);
	  if(inter >= 0)
	    {
	      image.data[row][col] = Colour(255, 255, 255);
	    }
	}
    }
  
  std::ofstream out("test.ppm");
  out << image;
  out.close();
  
  return 0;
}
