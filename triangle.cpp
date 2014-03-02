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
}

void Triangle::calculateNormal()
{
  normal = edgeA.cross(edgeB).normal();
}
