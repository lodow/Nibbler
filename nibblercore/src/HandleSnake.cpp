#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start)
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
}

void HandleSnake::drawn() const
{
  //draw stuff
}

void HandleSnake::addMember()
{
  //add a snake menber
}
