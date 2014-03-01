#ifndef _CAMERA_H
#define _CAMERA_H

#include "vector3.h"
#include "ray.h"

class Camera
{
  int width, height;
  // float xResolution, yResolution;

  Vector3 position;

  Vector3 u; // a step along the horizontal direction
  Vector3 v; // a step along the vertical direction

  Vector3 normal;

public:
  Camera();
  Camera(int w, int h);
  Camera(Vector3 pos, int w, int h);
  Ray getRay(int row, int col);

private:
  void init();
};

#endif
