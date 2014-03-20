#ifndef NIBBLER_H_
#define NIBBLER_H_

#include <dlfcn.h>

#include "Fault.hpp"
#include "IGui.hpp"
#include "HandleSnake.hpp"

class Nibbler
{
public :
  Nibbler(int width, int height);
  Nibbler();
  ~Nibbler();
public :
  void	run();
  void	setLib(void *lib);
private :
  IGui* (*_external_creator)();
  int _width;
  int _height;
  HandleSnake _game;
};

#endif
