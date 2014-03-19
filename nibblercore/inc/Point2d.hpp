#ifndef POINT2D_HPP_INCLUDED
#define POINT2D_HPP_INCLUDED

#include "Fault.hpp"

template<typename T>
class Point2d
{
public:
  Point2d(T x, T y);
  Point2d(const Point2d& p);
  ~Point2d();

  Point2d<T>& operator=(const Point2d& p);

  Point2d<T>& operator+(const Point2d& p) const;
  Point2d<T>& operator+=(const Point2d& p);

  Point2d<T>& operator-(const Point2d& p) const;
  Point2d<T>& operator-=(const Point2d& p);

  Point2d<T>& operator*(const Point2d& p) const;
  Point2d<T>& operator*=(const Point2d& p);

  Point2d<T>& operator/(const Point2d& p) const;
  Point2d<T>& operator/=(const Point2d& p);

private:
  T _x;
  T _y;
};


#endif // POINT2D_HPP_INCLUDED
