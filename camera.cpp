#include "camera.h"

Camera::Camera()
  : width(0), height(0), position(Vector3())
{}

Camera::Camera(int w, int h)
  : width(w), height(h), position(Vector3())
{
  init();
}

Camera::Camera(Vector3 pos, int w, int h)
  : width(w), height(h), position(pos)
{
  init();
}

void Camera::init()
{
  u = Vector3(0,1,0);
  v = Vector3(0,0,-1);

  normal = u.cross(v).normal();
}

Ray Camera::getRay(int row, int col)
{
  Vector3 start = position;
  start += u*col + v*row;

  return Ray(start, normal);
}

