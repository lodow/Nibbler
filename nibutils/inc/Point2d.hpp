#ifndef POINT2D_HPP_INCLUDED
#define POINT2D_HPP_INCLUDED

#include "Fault.hpp"

template<typename T>
class Point2d
{
public:
  Point2d(T x = 0, T y = 0);
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

  Point2d<T>& operator/(T p) const;
  Point2d<T>& operator/=(T p);

  T x() const {return _x;};
  T y() const {return _y;};

  T& x() {return _x;};
  T& y() {return _y;};

  T w() const {return _x;};
  T h() const {return _y;};

private:
  T _x;
  T _y;
};

#endif // POINT2D_HPP_INCLUDED
