#include "Apple.hpp"
#include "HandleSnake.hpp"

Apple::Apple(const Box<int>& b)
  : Entity(b, APPLE)
{
}

Apple::~Apple()
{
}

bool Apple::action(HandleSnake& game, Entity* collider)
{
  (void)collider;
  game.setScore(game.getScore() + 1);
  game.getHead()->addPart();
  game.createApple();
  return (true);
}
