#include "HandleSnake.hpp"

void deleteEntity(Entity* ent)
{
  delete ent;
}

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize,
                         TimeHandler& time, float basefps)
  : _win(win), _gamesize(gamesize),
    _snake(Box<int>(start, win / gamesize), true), _time(time), _baseFps(basefps)
{
  _lost = false;
  _dir = UP;
  _score = 0;
  createApple();
  _snake.addPart();
  _snake.addPart();
  _snake.addPart();
  _time.setFps(basefps);
  _acceleration = ((_gamesize.x() + _gamesize.y()) * 2.0f / (50.0f + 50.0f));
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
      if (_snake == *(*it))
        if ((*it)->action(*this, &_snake))
          {
            delete (*it);
            it = _ents.erase(it);
          }
    }
  if (_lost)
    {
      _time.setFps(_baseFps);
      _score = 0;
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
  bool tryAgain;
  size_t count = 0;
  Point2d<int> random;
  Box<int> apple(_snake.getBox());

  tryAgain = true;
  while (tryAgain && count < 750)
    {
      tryAgain = false;
      random.x() = rand();
      random.y() = rand();
      apple.getPos() = (random % _gamesize) * (_win / _gamesize);
      if (_snake.collisionIt(apple))
        tryAgain = true;
      else
        for (std::deque<Entity*>::const_iterator it = _ents.begin(); it != _ents.end(); ++it)
          if ((*it)->getBox() == apple)
            {
              tryAgain = true;
              break;
            }
      count++;
    }
  _ents.push_back(new Apple(apple));
}
