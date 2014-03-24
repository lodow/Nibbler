#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize)
  : _win(win), _gamesize(gamesize),
    _snake(Box<int>(start, win / gamesize))
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

void HandleSnake::update()
{
  Box<int> head = _snake.getBox();

  switch(_dir)
    {
    case UP:
      head.getPos().y() = (head.getPos().y() - head.getSize().h());
      break;
    case DOWN:
      head.getPos().y() = (head.getPos().y() + head.getSize().h());
      break;
    case LEFT:
      head.getPos().x() = (head.getPos().x() - head.getSize().w());
      break;
    case RIGHT:
      head.getPos().x() = (head.getPos().x() + head.getSize().w());
      break;
    default :
      break;
    }

  if((head.getPos().x() < 0 || head.getPos().x() > _win.w())
      || (head.getPos().y() < 0 || head.getPos().y() > _win.w()))
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
  while (tmp)
    {
      tmpb = tmp->getBox();
      lib->drawSquare(tmpb, QUEU_SNAKE);
      tmp = tmp->getNext();
    }
}

void HandleSnake::createApple()
{
  Point2d<int> apple;

  apple.x() = (rand() % _win.w()) / _gamesize.x();
  apple.y() = (rand() % _win.h()) / _gamesize.y();
  _apple = apple;
}

void HandleSnake::updateWinSize(const Point2d<int>& win)
{
  _win = win;
  //update sizeof snakeparts
}

