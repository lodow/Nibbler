#include "Menu.hpp"

Menu::Menu(Point2d<int> const &win)
{
  _win = win;
  _bestScore = 0;
  _score = 0;
}

Menu::~Menu()
{
}

void	Menu::updateScore(int score)
{
  if (score > _bestScore)
    _bestScore = score;
  _score = score;
}

void	Menu::Show(IGui *gui)
{
  std::stringstream txt1;
  std::stringstream txt2;
  std::stringstream txt3;

  txt1 << "Press ENTER to start";
  txt2 << "Or ESCAPE to exit";
  txt3 << "Best : " << _bestScore << " Your : " << _score;
  gui->clearScreen();
  gui->affText(Point2d<int>(40, _win.y() / 2 - _win.y() / 4), txt1);
  gui->affText(Point2d<int>(190, _win.y() / 2), txt2);
  gui->affText(Point2d<int>(210, _win.y() / 2 + _win.y() / 4), txt3);
}
