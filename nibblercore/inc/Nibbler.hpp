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

class Nibbler
{
public:
  Nibbler(const std::vector<std::string>& av);
  ~Nibbler();

  void run();

private:
  IGui *changeLib(const std::string& lib, IGui *lastGui);

  bool _exit;
  Point2d<int> _win;
  Point2d<int> _gamesize;
  TimeHandler _time;
  EventHandler _events;
  DLLoader<IGui*>* _lib;
};

#endif
