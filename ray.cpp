#include "ray.h"
#include "vector3.h"

Ray::Ray()
  : start(Vector3()), direction(Vector3())
{}

Ray::Ray(Vector3 strt, Vector3 dir)
  : start(strt), direction(dir)
{
  normalise();
}

void Ray::normalise()
{
  direction = direction.normal();
}

double square(const double x)
{
  return x*x;
}

double Ray::intersect(Vector3 center, double radius)
{
  Vector3 difference = start - center;
  
  return square(direction.dot(difference)) -
    difference.dot(difference) + square(radius);
}

