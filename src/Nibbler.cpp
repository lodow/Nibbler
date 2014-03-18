/*
** Nibbler.cpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:36:57 2014 Maxime
** Last update Tue Mar 18 22:25:24 2014 Maxime
*/

#include "Nibbler.hpp"

Nibbler::Nibbler(int x, int y)
{
  _y = y;
  _x = x;
  _map = new char* [_y];
  for (int i=0; i < _y; i++)
    _map[i] = new char[_x];
}

Nibbler::Nibbler()
{
  _x = 80;
  _y = 80;
  _map = new char* [_y];
  for (int i=0; i < _y; i++)
    _map[i] = new char[_x];
}

Nibbler::~Nibbler()
{
  for (int i=0; i < _y; i++)
    delete[] _map[i];
  delete[] _map;
}

void	Nibbler::setLib(void *lib)
{
  _external_creator = reinterpret_cast<IGui* (*)()>(dlsym(lib, "create_assistant"));
  if (_external_creator == NULL)
    throw nFault("Error with the shared lib\n");
}

void	Nibbler::run()
{
  IGraphique* gui = _external_creator();

  gui->createWindows(_x, _y);
}
