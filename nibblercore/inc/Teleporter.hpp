#ifndef TELEPORTER_HPP_INCLUDED
#define TELEPORTER_HPP_INCLUDED

#include "EventHandling.hpp"
#include "Entity.hpp"

class Teleporter : public Entity
{
public:
  Teleporter(const Box<int>& b, const Point2d<int>& dest, EventType dir);
  virtual ~Teleporter();

  bool operator==(const Entity& ent);

  virtual bool action(HandleSnake& game, Entity* collider);

private:
  Point2d<int> _dest;
  EventType _dir;
};

#endif // TELEPORTER_HPP_INCLUDED
