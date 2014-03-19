#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include "Box.hpp"

class SnakePart
{
public:
  SnakePart(const Box<int>& b);
  ~SnakePart();

  const Box<int>& getBox() const {return _box;};
  void setBox(const Box<int>& b) {_box = b;};

  void addPart();

  bool collisionItself() const;
  SnakePart* getNext() const {return _next;};

private:
  Box<int> _box;
  SnakePart* _next;
};

#endif // SNAKE_HPP_INCLUDED
