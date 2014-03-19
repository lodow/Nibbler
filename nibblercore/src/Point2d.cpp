#include "Point2d.hpp"


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

template class Point2d<int>;
template class Point2d<double>;
