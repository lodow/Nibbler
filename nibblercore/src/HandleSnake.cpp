#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start)
  : _snake(Box<int>(start, Point2d<int>(10, 10)))
{
}

HandleSnake::~HandleSnake()
{

}

void HandleSnake::changeDirection(int dir)
{
  _dir = dir;
}

int HandleSnake::getSize() const
{

  return (0);
}

void HandleSnake::update()
{
  //do moving stuff
  //first we update the snake position
  //check out of screen
  //we verifie collisoon:
  //we verifie that we are not on the apple:
}

void HandleSnake::drawn(IGui* lib) const
{
  //draw stuff
}

void HandleSnake::addMember()
{
  //add a snake menber
}
