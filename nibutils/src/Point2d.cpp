#include "Point2d.hpp"
#include <cmath>

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
Point2d<T>::Point2d(const Point2d& p)
  : _x(p._x), _y(p._y)
{

}

template<typename T>
Point2d<T>& Point2d<T>::operator=(const Point2d& p)
{
  _x = p._x;
  _y = p._y;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator+=(const Point2d& p)
{
  _x += p._x;
  _y += p._y;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator+(const Point2d& p) const
{
  Point2d* n = new Point2d(*this);
  *n += p;
  return (*n);
}

template<typename T>
Point2d<T>& Point2d<T>::operator-=(const Point2d& p)
{
  _x -= p._x;
  _y -= p._y;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator-(const Point2d& p) const
{
  Point2d* n = new Point2d(*this);
  *n -= p;
  return (*n);
}

template<typename T>
Point2d<T>& Point2d<T>::operator*=(const Point2d& p)
{
  _x *= p._x;
  _y *= p._y;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator*(const Point2d& p) const
{
  Point2d* n = new Point2d(*this);
  *n *= p;
  return (*n);
}

template<typename T>
Point2d<T>& Point2d<T>::operator/=(const Point2d& p)
{
  if (p._x == 0 || p._y == 0)
    throw nFault("Zero division", true);
  _x /= p._x;
  _y /= p._y;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator/(const Point2d& p) const
{
  Point2d* n = new Point2d(*this);
  *n /= p;
  return (*n);
}

template<typename T>
Point2d<T>& Point2d<T>::operator/=(T p)
{
  if (p == 0)
    throw nFault("Zero division", true);
  _x /= p;
  _y /= p;
  return (*this);
}

template<typename T>
Point2d<T>& Point2d<T>::operator/(T p) const
{
  Point2d* n = new Point2d(*this);
  *n /= p;
  return (*n);
}

template<typename T>
Point2d<T>& Point2d<T>::operator%=(const Point2d& p)
{
  if (p._x == 0.0 || p._y == 0.0)
    throw nFault("Zero division", true);
  _x %= p._x;
  _y %= p._y;
  return (*this);
}

template<>
Point2d<double>& Point2d<double>::operator%=(const Point2d<double>& p)
{
  if (p._x == 0.0 || p._y == 0.0)
    throw nFault("Zero division", true);
  _x = std::fmod(_x, p._x);
  _y = std::fmod(_y, p._y);
  return (*this);
}


template<typename T>
Point2d<T>& Point2d<T>::operator%(const Point2d& p) const
{
  Point2d* n = new Point2d(*this);
  *n %= p;
  return (*n);
}

template class Point2d<int>;
template class Point2d<double>;
