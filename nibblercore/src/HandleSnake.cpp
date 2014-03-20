#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win)
  : _win(win), _gamesize(10), _snake(Box<int>(start, Point2d<int>(_gamesize, _gamesize)))
{
  _lost = false;
  createApple();
}

HandleSnake::~HandleSnake()
{

}

void HandleSnake::changeDirection(Direction dir)
{
  _dir = dir;
}

int HandleSnake::getSize() const
{
// not implemented
  return (0);
}

void HandleSnake::update()
{
  Box<int> head = _snake.getBox();

  switch(_dir)
    {
    case UP:
      head.getPos().y() = (head.getPos().y() - _gamesize);
      break;
    case DOWN:
      head.getPos().y() = (head.getPos().y() + _gamesize);
      break;
    case LEFT:
      head.getPos().x() = (head.getPos().x() - _gamesize);
      break;
    case RIGHT:
      head.getPos().x() = (head.getPos().x() + _gamesize);
      break;
    default :
      break;
    }
  if((head.getPos().x() < 0 || head.getPos().x() > _win.w())
      || (head.getPos().x() < 0 || head.getPos().x() > _win.w()))
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

  // clear screen
  tmp = &_snake;
  while (tmp)
    {
      tmpb = tmp->getBox();
      lib->drawSquare(tmpb.getPos().x(), tmpb.getPos().y(), tmpb.getPos().w(), tmpb.getPos().h(), QUEU_SNAKE);
      tmp = tmp->getNext();
    }
  // draw screen
}

void HandleSnake::createApple()
{
  Point2d<int> apple;

  apple.x() = (rand() / _gamesize) % _win.w();
  apple.y() = (rand() / _gamesize) % _win.h();
  _apple = apple;
}

