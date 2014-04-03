#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "Point2d.hpp"
#include "Box.hpp"

class HandleSnake;

typedef enum {APPLE, HEAD, SNAKE, WALL, TELEP, EMPTY} blockType;

class Entity
{
public:
  Entity(const Box<int>& b, blockType type = EMPTY);
  virtual ~Entity();

  blockType getType() const {return _type;};
  const Box<int>& getBox() const {return _box;};
  virtual void setBox(const Box<int>& b) {_box = b;};

  bool operator==(const Entity& ent) {return (_box == ent.getBox());};

  virtual bool action(HandleSnake& game, Entity* collider);

protected:
  Box<int> _box;
  blockType _type;
};

#endif // ENTITY_HPP_INCLUDED
