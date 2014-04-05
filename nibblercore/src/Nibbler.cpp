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
  if (av.size() < 4 || av.size() > 5)
    throw nFault(std::string("Usage : ") + av[0] + " <width> <height> <libXXX.so>", false);

  ss.str(av[1]);
  ss >> tmp;
  gamesize.x() = tmp;
  if (tmp < 5 || tmp > 100)
    throw nFault(av[1] + ": incorrect value", false);
  ss.clear();
  ss.str(av[2]);
  ss >> tmp;
  gamesize.y() = tmp;
  if (tmp < 5 || tmp > 100)
    throw nFault(av[2] + ": incorrect value", false);

  lib = av[3];
  for (_libidx = 0; _libidx < libs.size() && libs[_libidx] != lib; _libidx++);
  _libidx++;

  _map = NULL;
  if (av.size() > 4)
    _map = new Map(av[4]);

  if (_map)
    gamesize = _map->getGamesize();
  _gamesize = gamesize;
  _win = _win - _win % _gamesize;
  if (gamesize.x() / gamesize.y() != 0)
    _win.y() = _win.x() / (gamesize.x() / gamesize.y());
  else if (gamesize.y() / gamesize.x() != 0)
    _win.x() = _win.y() / (gamesize.y() / gamesize.x());

  _lib = new DLLoader<IGui*>(lib);
}

void Nibbler::hud(const HandleSnake* game, IGui* gui) const
{
  std::stringstream score;

  score << game->getScore() << std::endl;
  gui->affText(Point2d<int>(5, 5), score);
}

HandleSnake* Nibbler::initGame()
{
  HandleSnake* res;

  if (_map)
    res =  new HandleSnake(*_map, _time, _win);
  else
    res = new HandleSnake(gameToWinSize(_gamesize / 2, _gamesize, _win), _win,
                          _gamesize, _time, (_gamesize.x() + _gamesize.y()) * 15.0f / (50.0f + 50.0f));
  return (res);
}

void Nibbler::run()
{
  IGui* gui;
  HandleSnake* game;
  Event ev;
  bool acted;
  bool aff_menu = true;
  Menu menu(_win);

  if ((gui = _lib->getInstance()) == NULL)
    throw nFault("Could not create the library windows", true);
  gui->createWindows(_win);
  while (!_exit)
    {
      game = initGame();
      game->changeDirection(UP);
      while ((!game->isOver() && !_exit))
        {
          acted = false;
          _time.startFrame();
          gui->updateEvent(_events);
          while (_events.pollEvent(ev))
            {
              if (ev.getEvent() == ENTER && aff_menu)
                aff_menu = !aff_menu;
              else if (ev.getEvent() == QUIT && aff_menu && ev.getDown())
                _exit = true;
              else if ((ev.getEvent() == QUIT || ev.getEvent() == PAUSE)
                       && !aff_menu && ev.getDown())
                aff_menu = true;
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
	  if (!aff_menu)
	    {
	      menu.updateScore(game->getScore());
	      game->update();
	    }
	  gui->clearScreen();
          if (aff_menu)
            menu.Show(gui);
	  game->drawn(gui);
	  hud(game, gui);
          gui->drawScreen();
          _time.endFrame();
          _time.alignOnFps();
        }
      delete game;
      aff_menu = true;
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
