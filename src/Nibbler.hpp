/*
** Nibbler.hpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:37:01 2014 Maxime
** Last update Wed Mar 12 16:21:19 2014 Maxime
*/

#ifndef NIBBLER_H_
#define NIBBLER_H_

#include <dlfcn.h>
#include "Fault.hpp"
#include "IGraphique.hpp"

class Nibbler
{
public :
  Nibbler(int x, int y);
  Nibbler();
  ~Nibbler();
public :
  void	run();
  void	setLib(void *lib);
private :
  IGraphique* (*_external_creator)();
  int _y;
  int _x;
  char	**_map;
};

#endif
