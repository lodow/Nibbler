#include "Teleporter.hpp"
#include "HandleSnake.hpp"

Teleporter::Teleporter(const Box<int>& b, const Point2d<int>& dest, EventType dir)
  : Entity(b, TELEP), _dest(dest), _dir(dir)
{
}

Teleporter::~Teleporter()
{
}

bool Teleporter::operator==(const Entity& ent)
{
  return (Entity::operator==(ent));
}

bool Teleporter::action(HandleSnake& game, Entity* collider)
{
  game.changeDirection(_dir);
  collider->setBox(_dest * _box.getSize());
  return (false);
}
