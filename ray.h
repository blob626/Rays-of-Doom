#ifndef _RAY_H
#define _RAY_H

#include "vector3.h"

class Ray
{
  Vector3 start;
  Vector3 direction;

public:
  Ray();
  Ray(Vector3 strt, Vector3 dir);

  double intersect(Vector3 center, double radius);
  // double intersect(Sphere sphere);
  // double intersect(Triangle triangle);
  // double intersect(Mesh mesh);
  
private:
  void normalise();
  
};

#endif
