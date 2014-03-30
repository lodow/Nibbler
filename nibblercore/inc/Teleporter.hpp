#ifndef TELEPORTER_HPP_INCLUDED
#define TELEPORTER_HPP_INCLUDED

#include "Entity.hpp"

class Teleporter : public Entity
{
public:
  Teleporter(const Box<int>& b, const Point2d<int>& dest);
  virtual ~Teleporter();

  bool operator==(Entity& ent);

private:
  Point2d<int> _dest;
};

#endif // TELEPORTER_HPP_INCLUDED
