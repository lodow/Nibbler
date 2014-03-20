#ifndef BOX_HPP_INCLUDED
#define BOX_HPP_INCLUDED

#include "Point2d.hpp"

template<typename T>
class Box
{
public:
  Box(const Point2d<T>& pos = Point2d<T>(0, 0), const Point2d<T>& size = Point2d<T>(0, 0));
  ~Box();

  Box(const Box& b);
  Box& operator=(const Box& b);

  const Point2d<T>& getPos() const {return _pos;};
  const Point2d<T>& getSize() const {return _size;};

  Point2d<T>& getPos() {return _pos;};
  Point2d<T>& getSize() {return _size;};

  bool operator==(const Box<T>& b) const;
  bool operator==(const Point2d<T>& b) const;

private:
  Point2d<T> _pos;
  Point2d<T> _size;
};

#endif // BOX_HPP_INCLUDED
