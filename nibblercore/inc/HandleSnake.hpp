#ifndef HANDLESNAKE_HPP_INCLUDED
#define HANDLESNAKE_HPP_INCLUDED

#include <cstdlib>
#include <deque>
#include <algorithm>
#include <iterator>

#include "Snake.hpp"
#include "Point2d.hpp"
#include "Box.hpp"
#include "IGui.hpp"
#include "Teleporter.hpp"
#include "Wall.hpp"
#include "Apple.hpp"
#include "TimeHandling.hpp"


class HandleSnake
{
public:
  HandleSnake(const Point2d<int>& start, const Point2d<int>& win, const Point2d<int>& gamesize,
              TimeHandler& time, float basefps);
  ~HandleSnake();

  void changeDirection(EventType dir);
  void update();
  void drawn(IGui* lib) const;

  int getScore() const {return _score;};
  bool isOver() const {return (_lost);};

  void setLost() {_lost = true;};

  void setScore(int score) {_score = score;};
  SnakePart* getHead() {return &_snake;};
  double getAcceleration() const {return _acceleration;};
  TimeHandler& getTime() const {return _time;};

  void createApple();

private:
  std::deque<Entity*> _ents;
  Point2d<int> _win;
  Point2d<int> _gamesize;
  EventType _dir;
  SnakePart _snake;
  TimeHandler& _time;
  int _score;
  bool _lost;
  double _acceleration;
  float _baseFps;
};

#endif // HANDLESNAKE_HPP_INCLUDED
