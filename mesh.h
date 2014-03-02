#ifndef _MESH_H
#define _MESH_H

#include <iostream>
#include <vector>
#include "triangle.h"

class Mesh
{
 public:
  
  std::vector<Triangle> faces;
  
  Mesh();
  Mesh(const char* file);
  
 private:
  void readFile(const char* file);
};

#endif
