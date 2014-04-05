#ifndef MENU_H_
#define MENU_H_

#include "IGui.hpp"
#include "Point2d.hpp"

class Menu
{
public:
  Menu(Point2d<int> const &win);
  ~Menu();
  void	updateScore(int score);
  void Show(IGui *gui);
private:
  Point2d<int> _win;
  int	       _bestScore;
  int		_score;
};

#endif
