#include "Nibbler.hpp"

Nibbler::Nibbler(const std::vector<std::string>& av)
  : _win(1024, 980), _time(15.0)
{
  std::stringstream ss;
  std::string lib;
  Point2d<int> gamesize;
  int tmp;

  _exit = false;
  if (av.size() != 4)
    throw nFault(std::string("Usage : ") + av[0] + " <width> <height> <libXXX.so>", false);

  ss.str(av[1]);
  ss >> tmp;
  gamesize.x() = tmp;
  if (tmp < 4 || tmp > 300)
    throw nFault(av[1] + ": incorrect value", false);
  ss.clear();
  ss.str(av[2]);
  ss >> tmp;
  gamesize.y() = tmp;
  if (tmp < 4 || tmp > 300)
    throw nFault(av[2] + ": incorrect value", false);
  lib = av[3];
  _gamesize = gamesize;
  _lib = new DLLoader<IGui*>(lib);
}

void Nibbler::run()
{
  IGui* gui;
  HandleSnake* game;
  Event ev;
  bool acted;

  if ((gui = _lib->getInstance()) == NULL)
    throw nFault("Could not create the library windows", true);
  gui->createWindows(_win);
  while (!_exit)
    {
      game = new HandleSnake(Point2d<int>(400, 300), _win, _gamesize);
      game->changeDirection(UP);
      while ((!game->isOver() && !_exit))
        {
          acted = false;
          _time.startFrame();
          gui->updateEvent(_events);
          while (_events.pollEvent(ev))
            {
              if (ev.getKey() == 27)
                _exit = true;
              if (ev.getDown() && ev.getKey() == 'z' && !acted)
                {
                  game->changeDirection(UP);
                  acted = true;
                }
              if (ev.getDown() && ev.getKey() == 's' && !acted)
                {
                  game->changeDirection(DOWN);
                  acted = true;
                }
              if (ev.getDown() && ev.getKey() == 'q' && !acted)
                {
                  game->changeDirection(LEFT);
                  acted = true;
                }
              if (ev.getDown() && ev.getKey() == 'd' && !acted)
                {
                  game->changeDirection(RIGHT);
                  acted = true;
                }
              //change lib ?
              ////updatewinsize ?? game->updateWinSize();
            }
          game->update();
          gui->clearScreen();
          game->drawn(gui);
          gui->drawScreen();
          _time.endFrame();
          _time.alignOnFps();
        }
      delete game;
    }
  delete gui;
}

Nibbler::~Nibbler()
{
  delete _lib;
}
