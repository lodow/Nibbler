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

  txt1 << "Press ENTER to start";
  txt2 << "Or ESCAPE to exit";
  gui->clearScreen();
  gui->affText(Point2d<int>(40, _win.y() / 2 - _win.y() / 4), txt1);
  gui->affText(Point2d<int>(190, _win.y() / 2), txt2);
}
