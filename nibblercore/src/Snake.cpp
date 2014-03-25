#include "Snake.hpp"

SnakePart::SnakePart(const Box<int>& b)
  : _box(b)
{
  _next = NULL;
}

SnakePart::~SnakePart()
{
  if(_next != NULL)
    delete _next;
}

void SnakePart::setBox(const Box<int>& b)
{
  if (_next)
    _next->setBox(_box);
  _box = b;
}

void SnakePart::addPart()
{
  if(_next != NULL)
    _next->addPart();
  else
    {
      Box<int> b(Point2d<int>(-50, -50), Point2d<int>(10, 10));
      _next = new SnakePart(b);
    }
}

bool SnakePart::collisionItself() const
{
  SnakePart* tmp = _next;

  while(tmp != NULL)
    {
      if (_box == tmp->getBox())
        return true;
      tmp = tmp->getNext();
    }
  return false;
}
