#include "Nibbler.hpp"

Nibbler::Nibbler(const std::vector<std::string>& av)
  : _win(800, 600)
{
  std::stringstream ss;
  std::string lib;
  Point2d<int> gamesize;
  int tmp;

  if (av.size() != 4)
    throw nFault(std::string("Usage : ") + av[0] + " <width> <height> <libXXX.so>", false);

  ss.str(av[1]);
  ss >> tmp;
  gamesize.x() = tmp;
  if (tmp < 4 || tmp > 100)
    throw nFault(av[1] + ": incorrect value", false);
  ss.clear();
  ss.str(av[2]);
  ss >> tmp;
  gamesize.y() = tmp;
  if (tmp < 4 || tmp > 100)
    throw nFault(av[2] + ": incorrect value", false);
  lib = av[3];
  _lib = new DLLoader<IGui*>(lib);
  _game = new HandleSnake(gamesize / 2, _win, gamesize);
}

void Nibbler::run()
{
  IGui* gui;

  if ((gui = _lib->getInstance()) == NULL)
    std::cout << _win.w() << " " << _win.h() << std::endl;
  gui->createWindows(_win.w(), _win.h());
  _game->changeDirection(UP);
  while (!_game->isOver())
    {
      //getevent
      //change lib ?
      //updatewinsize ?? _game->updateWinSize();
      //_game->changeDirection(X);
      _game->update();
      // clear screen
      _game->drawn(gui);
      // draw screen
      //sleep
    }
  delete gui;
}

Nibbler::~Nibbler()
{
  delete _lib;
  delete _game;
}

