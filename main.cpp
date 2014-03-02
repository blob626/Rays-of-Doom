#include <iostream>
#include <fstream>
#include <cmath>
#include "vector3.h"
#include "image.h"
#include "camera.h"
#include "ray.h"
#include "triangle.h"

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

  Triangle tri(Vector3(0, 50, -60),Vector3(0, 30, -20),Vector3(0, 70, -20));

  
  
  for(int row = 0; row < height; ++row)
    {
      for(int col = 0; col < width; ++col)
	{
	  
	  Ray ray = camera.getRay(row,col);
	  //	  double inter = ray.intersect(sphereCenter,radius);
	  bool inter = ray.intersect(tri);
	  if(inter)
	    {

	      int color = 255;//floor(inter);
	      image.data[row][col] = Colour(color, color, color);
	    }
	}
    }
  
  std::ofstream out("test.ppm");
  out << image;
  out.close();
  
  return 0;
}
