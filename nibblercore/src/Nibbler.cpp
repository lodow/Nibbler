#include "Nibbler.hpp"

Nibbler::Nibbler(const std::vector<std::string>& av, const std::vector<std::string>& libs)
  : _win(1024, 980), _time(15.0)
{
  std::stringstream ss;
  std::string lib;
  Point2d<int> gamesize;
  int tmp;

  _libsList = libs;
  _libidx = 0;
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
  for (_libidx = 0; _libidx < libs.size() && libs[_libidx] != lib; _libidx++);
  _libidx++;
  _gamesize = gamesize;
  _win = _win - _win % _gamesize;
  if (gamesize.x() / gamesize.y() != 0)
    _win.y() = _win.x() / (gamesize.x() / gamesize.y());
  else if (gamesize.y() / gamesize.x() != 0)
    _win.x() = _win.y() / (gamesize.y() / gamesize.x());
  _time.setFps((gamesize.x() + gamesize.y()) * 15.0f / (50.0f + 50.0f));
  _lib = new DLLoader<IGui*>(lib);
}

void Nibbler::run()
{
  IGui* gui;
  HandleSnake* game;
  Event ev;
  bool acted;
  float add;

  add = ((_gamesize.x() + _gamesize.y()) * 4.0f / (50.0f + 50.0f));

  if ((gui = _lib->getInstance()) == NULL)
    throw nFault("Could not create the library windows", true);
  gui->createWindows(_win);
  while (!_exit)
    {
      game = new HandleSnake(Point2d<int>((_gamesize.x() / 2) * (_win.x() / _gamesize.x()),
                                          (_gamesize.y() / 2) * (_win.y() / _gamesize.y())),
                             _win, _gamesize);
      game->changeDirection(UP);
      while ((!game->isOver() && !_exit))
        {
          acted = false;
          _time.startFrame();
          gui->updateEvent(_events);
          while (_events.pollEvent(ev))
            {
              if (ev.getEvent() == QUIT)
                _exit = true;
              else if (ev.getDown() && !acted
                       && (ev.getEvent() == UP || ev.getEvent() == DOWN
                           || ev.getEvent() == RIGHT || ev.getEvent() == LEFT))
                {
                  game->changeDirection(ev.getEvent());
                  acted = true;
                }
              else if (!ev.getDown() && ev.getEvent() == CHANGELIB && _libsList.size() > 0)
                {
                  gui = changeLib(_libsList.at(_libidx % _libsList.size()), gui);
                  _libidx++;
                }
            }
          game->update(_time, add);
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

IGui *Nibbler::changeLib(const std::string& nlib, IGui *lastGui)
{
  DLLoader<IGui*>* lib;
  IGui* gui;
  bool ok;

  lib = NULL;
  gui = NULL;
  ok = false;
  try
    {
      lib = new DLLoader<IGui*>(nlib);
      if ((gui = lib->getInstance()) == NULL)
        throw nFault("Could not create the library windows", true);
      gui->createWindows(_win);
      ok = true;
      delete lastGui;
      delete _lib;
      _lib = lib;
    }
  catch (std::exception& e)
    {
      delete gui;
      delete lib;
      std::cerr << e.what() << std::endl;
    }
  return (ok ? gui : lastGui);
}

Nibbler::~Nibbler()
{
  delete _lib;
}
