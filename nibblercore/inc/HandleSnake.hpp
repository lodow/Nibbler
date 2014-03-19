#ifndef HANDLESNAKE_HPP_INCLUDED
#define HANDLESNAKE_HPP_INCLUDED

#include "Point2d.hpp"

class HandleSnake
{
public:
  HandleSnake(const Point2d<int>& start);
  ~HandleSnake();

  void changeDirection(int dir);
  void update();
  void drawn() const;

  int getSize() const;
  void addMember();

  bool isOver() const {return (_lost);};

private:
  int _dir;
  Point2d<int> _apple;
  int _score;
  bool _lost;
};


#endif // HANDLESNAKE_HPP_INCLUDED
