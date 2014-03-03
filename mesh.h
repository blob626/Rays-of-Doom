#ifndef _MESH_H
#define _MESH_H

#include <iostream>
#include <vector>
#include <map>
#include "triangle.h"

class Mesh
{
  // std::map<int, std::vector<int> > graph;
  
 public:
  std::vector<Vector3> verts;
  std::vector<Triangle> faces;
  
  Mesh();
  Mesh(const char* file);
  
 private:
  void readFile(const char* file);
  void constructBounds();
};

#endif
