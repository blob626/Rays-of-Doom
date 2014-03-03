#include "triangle.h"
#include "vector3.h"

Triangle::Triangle()
  : vertexA(Vector3()), vertexB(Vector3()), vertexC(Vector3())
{}

Triangle::Triangle(Vector3 a, Vector3 b, Vector3 c)
  : vertexA(a), vertexB(b), vertexC(c)
{
  init();
}

void Triangle::init()
{
  edgeA = vertexB - vertexA;
  edgeB = vertexC - vertexA;

  calculateNormal();
  calculateCenter();
  calculateRadius();
}

void Triangle::calculateNormal()
{
  normal = edgeA.cross(edgeB).normal();
}

void Triangle::calculateCenter()
{
  center = vertexA + vertexB + vertexC;
  center.x /= 3;
  center.y /= 3;
  center.z /= 3;
}

void Triangle::calculateRadius()
{
  double v1 = (vertexA - center).magnitude();
  double v2 = (vertexB - center).magnitude();
  double v3 = (vertexC - center).magnitude();

  if(v1 > v2)
    {
      radius = v1 > v3 ? v1 : v3;
    }
  else
    {
      radius = v2 > v3 ? v2 : v3;
    }
}
