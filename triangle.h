#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "vector3.h"
#include "sphere.h"

class Triangle
{
public:
  Vector3 vertexA, vertexB, vertexC;
  Vector3 normal;
  Vector3 center;
  double radius;
  Vector3 edgeA;
  Vector3 edgeB;
  
  Triangle();
  Triangle(Vector3 a, Vector3 b, Vector3 c);

private:
  void init();
  void calculateNormal();
  void calculateCenter();
  void calculateRadius();
};

#endif
