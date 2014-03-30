#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "Point2d.hpp"
#include "Box.hpp"

typedef enum {APPLE, SNAKE, WALL, EMPTY} blockType;

class Entity
{
public:
  Entity(const Box<int>& b, blockType type = EMPTY);
  virtual ~Entity();

  blockType getType() const {return _type;};
  const Box<int>& getBox() const {return _box;};
  virtual void setBox(const Box<int>& b) {_box = b;};

  bool operator==(const Entity& ent) {return (_box == ent.getBox());};
protected:
  Box<int> _box;
  blockType _type;
};

#endif // ENTITY_HPP_INCLUDED
