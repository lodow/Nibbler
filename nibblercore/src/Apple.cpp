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
  game.setScore(game.getScore() + _box.getSize().x());
  game.getHead()->addPart();
  game.createApple();
  game.getTime().setFps(game.getTime().getFps() + game.getAcceleration());
  return (true);
}
