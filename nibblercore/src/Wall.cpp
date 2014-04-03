#include "Wall.hpp"
#include "HandleSnake.hpp"

Wall::Wall(const Box<int>& b)
  : Entity(b, WALL)
{

}

Wall::~Wall()
{

}

bool Wall::action(HandleSnake& game, Entity* collider)
{
  (void)collider;
  game.setLost();
  return (false);
}
