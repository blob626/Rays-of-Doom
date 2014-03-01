#include <iostream>
#include <fstream>
#include "vector3.h"
#include "image.h"

int main(int argc, char* argv[])
{
  Vector3 origin;
  Vector3 a(1, 0, 0);
  Vector3 b(0, 1, 0);
  Vector3 c(0, 0, 1);

  std::cout << a.cross(b).normal().magnitude() << std::endl;

  std::ofstream out("test.ppm");
  out << Image(4, 4);
  out.close();
  
  return 0;
}
