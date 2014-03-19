/*
** Nibbler.hpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:37:01 2014 Maxime
** Last update Tue Mar 18 22:24:06 2014 Maxime
*/

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
