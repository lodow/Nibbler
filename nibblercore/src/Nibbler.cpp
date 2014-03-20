#include "Nibbler.hpp"

Nibbler::Nibbler(const std::vector<std::string>& av)
{
  std::stringstream ss;
  std::string lib;
  Point2d<int> win;
  int tmp;

  if (av.size() != 4)
    throw nFault(std::string("Usage : ") + av[0] + " <width> <height> <libXXX.so>", false);

  ss.str(av[1]);
  ss >> tmp;
  win.x() = tmp;
  if (tmp < 400 || tmp > 2000)
    throw nFault(av[1] + ": incorrect value", false);
  ss.str(av[2]);
  ss >> tmp;
  win.y() = tmp;
  if (tmp < 400 || tmp > 2000)
    throw nFault(av[2] + ": incorrect value", false);
  lib = av[3];
  _lib = new DLLoader<IGui*>(lib);
  _game = new HandleSnake(win / 2, win);
  _win = win;
}

void Nibbler::run()
{
  while (!_game->isOver())
    {
      _game->update();
      _game->drawn(_lib->getInstance());
    }
}

Nibbler::~Nibbler()
{
  delete _lib;
  delete _game;
}

