#ifndef _SPHERE_H
#define _SPHERE_H

#include "vector3.h"

class Sphere
{
 public:
  Vector3 center;
  double radius;
  
  Sphere(Vector3 cent, double r);
};

#endif
