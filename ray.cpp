#include "ray.h"
#include "vector3.h"
#include "triangle.h"

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

Vector3 Ray::intersectionPoint(Vector3 point, Vector3 normal)
{
  return start + direction*(((point-start).dot(normal))/(direction.dot(normal)));
}

bool Ray::intersect(Triangle triangle)
{
  Vector3 point = intersectionPoint(triangle.vertexA, triangle.normal);

  Vector3 edgeC = point - triangle.vertexA;

  double AA = triangle.edgeA.dot(triangle.edgeA);
  double BB = triangle.edgeB.dot(triangle.edgeB);
  double AB = triangle.edgeA.dot(triangle.edgeB);
  double AC = triangle.edgeA.dot(edgeC);
  double BC = triangle.edgeB.dot(edgeC);
  
  double D = AA*BB - AB*AB;

  if(D != 0)
    {
      double u = (BB*AC - AB*BC)/D;
      double v = (AA*BC - AB*AC)/D;

      if(u+v <= 1 && (v >= 0 && u >= 0))
	{
	  return true;
	}
    }
  return false;
  
}

double Ray::intersect(Vector3 center, double radius)
{
  Vector3 difference = start - center;
  
  return square(direction.dot(difference)) -
    difference.dot(difference) + square(radius);
}

