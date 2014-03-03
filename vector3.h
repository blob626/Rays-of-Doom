#ifndef _VECTOR3_H
#define _VECTOR3_H

#include <iostream>

class Vector3
{
public:
  double x, y, z;

  Vector3();
  Vector3(double _x, double _y, double _z);
  Vector3 operator+(const Vector3 &other) const;
  Vector3 operator-(const Vector3 &other) const;

  // treat * as the scalar ultiply of vector
  Vector3 operator*(const double &scalar) const;
  double dot(const Vector3 &other) const;
  Vector3 cross(const Vector3 &other) const;
  Vector3& operator+=(const Vector3 &other);

  Vector3 normal();
  double magSquare() const;
  double magnitude() const;

  // prints the vector in the format <x,y,z>
  friend std::ostream& operator<<(std::ostream& stream, Vector3 vec);
  friend std::istream& operator>>(std::istream& stream, Vector3& vec);
};


  
#endif
