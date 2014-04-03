#ifndef MENU_H_
#define MENU_H_

#include "IGui.hpp"
#include "Point2d.hpp"

class Menu
{
public:
  Menu(Point2d<int> const &win);
  ~Menu();
  void Show(IGui *gui);
private:
  Point2d<int> _win;
};

#endif
