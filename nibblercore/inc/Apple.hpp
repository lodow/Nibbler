#ifndef APPLE_HPP_INCLUDED
#define APPLE_HPP_INCLUDED

#include "Entity.hpp"

class Apple : public Entity
{
public:
  Apple(const Box<int>& b);
  virtual ~Apple();

  virtual bool action(HandleSnake& game, Entity* collider);

private:
};

#endif // APPLE_HPP_INCLUDED
