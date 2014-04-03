#ifndef WALL_HPP_INCLUDED
#define WALL_HPP_INCLUDED

#include "Entity.hpp"

class Wall : public Entity
{
public:
  Wall(const Box<int>& b);
  virtual ~Wall();
private:
};

#endif // WALL_HPP_INCLUDED
