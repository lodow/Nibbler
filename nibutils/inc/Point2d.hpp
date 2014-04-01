#ifndef POINT2D_HPP_INCLUDED
#define POINT2D_HPP_INCLUDED

#include <cmath>

#include "Fault.hpp"

template<typename T>
class Point2d
{
public:
  Point2d(T x = 0, T y = 0);

  template<typename U>
  Point2d(const Point2d<U>& p);

  ~Point2d();

  template<typename U>
  Point2d<T>& operator=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator+(const Point2d<U>& p) const;

  template<typename U>
  Point2d<T>& operator+=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator-(const Point2d<U>& p) const;

  template<typename U>
  Point2d<T>& operator-=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator*(const Point2d<U>& p) const;

  template<typename U>
  Point2d<T>& operator*=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator/(const Point2d<U>& p) const;
  template<typename U>
  Point2d<T>& operator/=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator%(const Point2d<U>& p) const;
  template<typename U>
  Point2d<T>& operator%=(const Point2d<U>& p);

  template<typename U>
  Point2d<T>& operator/(U p) const;

  template<typename U>
  Point2d<T>& operator/=(U p);

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

template<typename T>
Point2d<T>::Point2d(T x, T y)
  : _x(x), _y(y)
{

}

template<typename T>
Point2d<T>::~Point2d()
{

}

template<typename T>
template<typename U>
Point2d<T>::Point2d(const Point2d<U>& p)
  : _x(p._x), _y(p._y)
{

}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator=(const Point2d<U>& p)
{
  _x = p._x;
  _y = p._y;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator+=(const Point2d<U>& p)
{
  _x += p._x;
  _y += p._y;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator+(const Point2d<U>& p) const
{
  Point2d* n = new Point2d(*this);
  *n += p;
  return (*n);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator-=(const Point2d<U>& p)
{
  _x -= p._x;
  _y -= p._y;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator-(const Point2d<U>& p) const
{
  Point2d* n = new Point2d(*this);
  *n -= p;
  return (*n);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator*=(const Point2d<U>& p)
{
  _x *= p._x;
  _y *= p._y;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator*(const Point2d<U>& p) const
{
  Point2d* n = new Point2d(*this);
  *n *= p;
  return (*n);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator/=(const Point2d<U>& p)
{
  if (p._x == 0 || p._y == 0)
    throw nFault("Zero division", true);
  _x /= p._x;
  _y /= p._y;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator/(const Point2d<U>& p) const
{
  Point2d* n = new Point2d(*this);
  *n /= p;
  return (*n);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator/=(U p)
{
  if (p == 0)
    throw nFault("Zero division", true);
  _x /= p;
  _y /= p;
  return (*this);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator/(U p) const
{
  Point2d* n = new Point2d(*this);
  *n /= p;
  return (*n);
}

template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator%=(const Point2d<U>& p)
{
  if (p._x == 0.0 || p._y == 0.0)
    throw nFault("Zero division", true);
  _x %= p._x;
  _y %= p._y;
  return (*this);
}

template<>
template<typename U>
Point2d<double>& Point2d<double>::operator%=(const Point2d<U>& p)
{
  if (p._x == 0.0 || p._y == 0.0)
    throw nFault("Zero division", true);
  _x = std::fmod(_x, p._x);
  _y = std::fmod(_y, p._y);
  return (*this);
}


template<typename T>
template<typename U>
Point2d<T>& Point2d<T>::operator%(const Point2d<U>& p) const
{
  Point2d* n = new Point2d(*this);
  *n %= p;
  return (*n);
}

#endif // POINT2D_HPP_INCLUDED
