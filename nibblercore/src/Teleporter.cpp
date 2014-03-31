#include "Teleporter.hpp"

Teleporter::Teleporter(const Box<int>& b, const Point2d<int>& dest)
  : Entity(b, TELEP), _dest(dest)
{
}

Teleporter::~Teleporter()
{
}

bool Teleporter::operator==(Entity& ent)
{
  bool res;

  res = Entity::operator==(ent);
  if (res)
    ent.setBox(_dest * _box.getSize());
  return (res);
}

