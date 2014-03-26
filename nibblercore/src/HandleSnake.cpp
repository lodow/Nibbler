#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize)
  : _win(win), _gamesize(gamesize),
    _snake(Box<int>(start, win / gamesize))
{
  _lost = false;
  _dir = UP;
  srand(time(NULL));
  createApple();
}

HandleSnake::~HandleSnake()
{

}

void HandleSnake::changeDirection(Direction dir)
{
  if ((_dir == UP && dir != DOWN)
      || (_dir == DOWN && dir != UP)
      || (_dir == LEFT && dir != RIGHT)
      || (_dir == RIGHT && dir != LEFT))
    _dir = dir;
}

void HandleSnake::update()
{
  Box<int> head = _snake.getBox();

  head.getPos().y() += ((_dir == UP) * (-head.getSize().h()))
                       + ((_dir == DOWN) * (head.getSize().h()));
  head.getPos().x() += ((_dir == LEFT) * (-head.getSize().w()))
                       + ((_dir == RIGHT) * (head.getSize().w()));

  if((head.getPos().x() < 0 || head.getPos().x() > _win.w() - _gamesize.x())
      || (head.getPos().y() < 0 || head.getPos().y() > _win.h() - _gamesize.y()))
    _lost = true;

  _snake.setBox(head);

  if(_snake.collisionItself())
    _lost = true;

  if (_snake.getBox() == _apple)
    {
      _score += 1;
      _snake.addPart();
      createApple();
    }
}

void HandleSnake::drawn(IGui* lib) const
{
  const SnakePart* tmp;
  Box<int> tmpb;

  tmp = &_snake;
  tmpb = tmp->getBox();
  tmpb.getPos() = _apple;
  lib->drawSquare(tmpb, APPLE);
  while (tmp)
    {
      tmpb = tmp->getBox();
      lib->drawSquare(tmpb, SNAKE);
      tmp = tmp->getNext();
    }
}

void HandleSnake::createApple()
{
  Point2d<int> random(rand(), rand());

  _apple = (random % _gamesize) * ((_win - _gamesize) / _gamesize);
}

void HandleSnake::updateWinSize(const Point2d<int>& win)
{
  _win = win;
  //update sizeof snakeparts
}

