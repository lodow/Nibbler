#include "Menu.hpp"

Menu::Menu(Point2d<int> const &win)
{
  _win = win;
}

Menu::~Menu()
{
}

void	Menu::Show(IGui *gui)
{
  std::stringstream txt1;
  std::stringstream txt2;
  std::stringstream txt3;
  std::stringstream txt4;

  txt1 << "Press ENTER to start";
  txt2 << "ESCAPE to exit or pause";
  txt3 << "O to change graphic libraries";
  txt4 << "Arrow keys to control the snake";
  gui->affText(Point2d<int>(40, _win.y() / 2 - _win.y() / 3), txt1);
  gui->affText(Point2d<int>(40, _win.y() / 2 - _win.y() / 4), txt2);
  gui->affText(Point2d<int>(40, _win.y() / 2 - _win.y() / 8), txt3);
  gui->affText(Point2d<int>(40, _win.y() - _win.y() / 2), txt4);
}
