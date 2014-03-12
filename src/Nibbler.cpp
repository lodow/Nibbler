/*
** Nibbler.cpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:36:57 2014 Maxime
** Last update Wed Mar 12 16:07:28 2014 Maxime
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

/*void	Nibbler::setLib(void *lib)
{

}*/

void	Nibbler::run()
{

}
