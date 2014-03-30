#include "HandleSnake.hpp"

void deleteEntity(Entity* ent)
{
  delete ent;
}

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize)
  : _win(win), _gamesize(gamesize),
    _snake(Box<int>(start, win / gamesize), true)
{
  _lost = false;
  _dir = UP;
  srand(time(NULL));
  createApple();
  _snake.addPart();
  _snake.addPart();
  _snake.addPart();
}

HandleSnake::~HandleSnake()
{
  std::for_each(_ents.begin(), _ents.end(), &deleteEntity);
}

void HandleSnake::changeDirection(EventType dir)
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

  if((head.getPos().x() < 0 || head.getPos().x() / _gamesize.x() >= (_win.w() / _gamesize.x()))
      || (head.getPos().y() < 0 || head.getPos().y() / _gamesize.y() >= (_win.h() / _gamesize.y())))
    _lost = true;

  _snake.setBox(head);

  if(_snake.collisionItself())
    _lost = true;

  for (std::deque<Entity*>::iterator it = _ents.begin(); it != _ents.end(); ++it)
    {
      if ((_snake == *(*it)) && ((*it)->getType() == APPLE))
        {
          delete (*it);
          _ents.erase(it);
          _score += 1;
          _snake.addPart();
          createApple();
        }
    }
}

void HandleSnake::drawn(IGui* lib) const
{
  const SnakePart* tmp;

  for (std::deque<Entity*>::const_iterator it = _ents.begin(); it != _ents.end(); ++it)
    lib->drawSquare((*it)->getBox(), (*it)->getType());
  tmp = &_snake;
  while (tmp)
    {
      lib->drawSquare(tmp->getBox(), tmp->getType());
      tmp = tmp->getNext();
    }
}

void HandleSnake::createApple()
{
  Point2d<int> random(rand(), rand());
  Box<int> apple(_snake.getBox());

  apple.getPos() = (random % _gamesize) * (_win / _gamesize);
  _ents.push_back(new Entity(apple, APPLE));
}

void HandleSnake::updateWinSize(const Point2d<int>& win)
{
  Box<int> tmp;

  _win = win;
  tmp = _snake.getBox();
  tmp.getSize() = win / _gamesize;
  _snake.setBox(tmp);
}

