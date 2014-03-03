#include <iostream>
#include <fstream>
#include <cmath>
#include "vector3.h"
#include "image.h"
#include "camera.h"
#include "ray.h"
#include "triangle.h"
#include "mesh.h"

int main(int argc, char* argv[])
{
  int width = 100;
  int height = 100;

  Image image(width, height, 255);
  Camera camera(width, height);

  Mesh mesh("test.obj");
  std::cout << "finished reading in file" << std::endl;
  for(int row = 0; row < height; ++row)
    {
      for(int col = 0; col < width; ++col)
	{
	  
	  Ray ray = camera.getRay(row,col);
	  double inter = ray.intersect(mesh);
	  if(inter > 0)
	    {

	      int color = 255;//floor(inter*255);
	      image.data[row][col] = Colour(color, color, color);
	    }
	}
    }
  
  std::ofstream out("test.ppm");
  out << image;
  out.close();
  
  return 0;
}
