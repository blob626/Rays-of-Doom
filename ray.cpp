#include "ray.h"
#include "vector3.h"
#include "triangle.h"
#include "mesh.h"

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

double Ray::intersect(Triangle triangle)
{

  // check if the normal is facing the right direction
  if(direction.dot(triangle.normal) < 0)
    {
      return -1;
    }

  // check if the bounding sphere is hit
  Vector3 difference = start - triangle.center;
  if(square(direction.dot(difference)) -  difference.dot(difference) + square(triangle.radius) < 0)
    {
      return -1;
    }
  
  // get the actual intersectoin point
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
	  return u+v;
	}
    }
  return -1;
  
}

double Ray::intersect(Sphere sphere)
{
  Vector3 difference = start - sphere.center;
  
  return square(direction.dot(difference)) -
    difference.dot(difference) + square(sphere.radius);
}

double Ray::intersect(Mesh mesh)
{
  for(int i = 0; i < mesh.faces.size(); ++i)
    {
      double intersection = intersect(mesh.faces[i]);
      if(intersection >= 0)
	{
	  return intersection;
	}
    }
  return -1;
}
