#include "vector3.h"
#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(double _x, double _y, double _z)
  : x(_x), y(_y), z(_z)
{}

Vector3 Vector3::operator+(const Vector3 &other) const
{
  return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
  return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const double &scalar) const
{
  return Vector3(x*scalar, y*scalar, z*scalar);
}

double Vector3::dot(const Vector3 &other) const
{
  return (x*other.x + y*other.y + z*other.z);
}

Vector3 Vector3::cross(const Vector3 &other) const
{
  return Vector3(y*other.z - z*other.y,
		 z*other.x - x*other.z,
		 x*other.y - y*other.x);
}

Vector3& Vector3::operator+=(const Vector3 &other)
{
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3 Vector3::normal()
{
  return (*this)*(1/sqrt(dot(*this)));
}

double Vector3::magSquare() const
{
  return dot(*this);
}

double Vector3::magnitude() const
{
  return sqrt(magSquare());
}

std::ostream& operator<<(std::ostream& stream, Vector3 vec)
{
  stream << "<" << vec.x <<"," << vec.y <<","<<vec.z<<">";
  return stream;
}

std::istream& operator>>(std::istream& stream, Vector3& vec)
{
  stream >> vec.x >> vec.y >> vec.z;
  return stream;
}
