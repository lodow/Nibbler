#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include "Entity.hpp"
#include "Box.hpp"

class SnakePart : public Entity
{
public:
  SnakePart(const Box<int>& b, bool isHead = false);
  virtual ~SnakePart();

  virtual void setBox(const Box<int>& b);

  void addPart();

  bool collisionItself() const;
  bool collisionIt(const Box<int>& b) const;

  SnakePart* getNext() const {return _next;};
private:
  SnakePart* _next;
};

#endif // SNAKE_HPP_INCLUDED
