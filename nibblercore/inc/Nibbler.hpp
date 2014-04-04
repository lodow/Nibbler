#ifndef NIBBLER_H_
#define NIBBLER_H_

#include <vector>
#include <string>
#include <sstream>

#include "DLLoader.hpp"
#include "Fault.hpp"
#include "IGui.hpp"
#include "TimeHandling.hpp"
#include "EventHandling.hpp"
#include "HandleSnake.hpp"
#include "Menu.hpp"
#include "Map.hpp"

class Nibbler
{
public:
  Nibbler(const std::vector<std::string>& av, const std::vector<std::string>& libs = std::vector<std::string>());
  ~Nibbler();

  HandleSnake* initGame();
  void run();
  void hud(const HandleSnake* game, IGui* gui) const;

private:
  IGui *changeLib(const std::string& lib, IGui *lastGui);

  bool _exit;
  Point2d<int> _win;
  Point2d<int> _gamesize;
  TimeHandler _time;
  EventHandler _events;
  DLLoader<IGui*>* _lib;
  unsigned int _libidx;
  std::vector<std::string> _libsList;
  Map* _map;
};

#endif
