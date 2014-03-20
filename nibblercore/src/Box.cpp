#include "Box.hpp"

template<typename T>
Box<T>::Box(const Point2d<T>& pos, const Point2d<T>& size)
  : _pos(pos), _size(size)
{

}

template<typename T>
Box<T>::~Box()
{
}

template<typename T>
Box<T>::Box(const Box<T>& b)
{
  _pos = b._pos;
  _size = b._size;
}

template<typename T>
Box<T>& Box<T>::operator=(const Box<T>& b)
{
  _pos = b._pos;
  _size = b._size;
  return (*this);
}

template<typename T>
bool Box<T>::operator==(const Box<T>& box2) const
{
  if((box2._pos.x() >= _pos.x() + _size.w())
      || (box2._pos.x() + box2._size.w() <= _pos.x())
      || (box2._pos.y() >= _pos.y() + _size.h())
      || (box2._pos.y() + box2._size.h() <= _pos.y()))
    return false;
  return true;
}

template<typename T>
bool Box<T>::operator==(const Point2d<T>& point) const
{
  Box<T> box2(point, _size);

  if((box2._pos.x() >= _pos.x() + _size.w())
      || (box2._pos.x() + box2._size.w() <= _pos.x())
      || (box2._pos.y() >= _pos.y() + _size.h())
      || (box2._pos.y() + box2._size.h() <= _pos.y()))
    return false;
  return true;
}

template class Box<int>;
template class Box<double>;
