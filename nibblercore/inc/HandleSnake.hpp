#ifndef HANDLESNAKE_HPP_INCLUDED
#define HANDLESNAKE_HPP_INCLUDED

#include <cstdlib>

#include "Snake.hpp"
#include "Point2d.hpp"
#include "Box.hpp"
#include "IGui.hpp"

typedef enum {UP, DOWN, RIGHT, LEFT} Direction;

class HandleSnake
{
public:
  HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize);
  ~HandleSnake();

  void updateWinSize(const Point2d<int>& win);
  void changeDirection(Direction dir);
  void update();
  void drawn(IGui* lib) const;

  int getScore() const {return _score;};
  bool isOver() const {return (_lost);};

private:
  void createApple();

  Point2d<int> _win;
  Point2d<int> _gamesize;
  Direction _dir;
  SnakePart _snake;
  Point2d<int> _apple;
  int _score;
  bool _lost;
};

#endif // HANDLESNAKE_HPP_INCLUDED
