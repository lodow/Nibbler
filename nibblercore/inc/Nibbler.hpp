#ifndef NIBBLER_H_
#define NIBBLER_H_

#include <vector>
#include <string>
#include <sstream>

#include "DLLoader.hpp"
#include "Fault.hpp"
#include "IGui.hpp"
#include "TimeHandling.hpp"
#include "HandleSnake.hpp"

class Nibbler
{
public:
  Nibbler(const std::vector<std::string>& av);
  ~Nibbler();

  void run();

private:
  Point2d<int> _win;
  TimeHandler _time;
  DLLoader<IGui*>* _lib;
  HandleSnake* _game;
};

#endif
