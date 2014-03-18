/*
** Graphique.hpp for nibbler in /home/maxime/projet/actu/cpp_nibbler/src_sdl
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:18:50 2014 Maxime
** Last update Tue Mar 18 22:34:17 2014 Maxime
*/

#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

#include <iostream>
#include "../src/IGui.hpp"

class Graphique : public IGui
{
public :
  Graphique();
  ~Graphique();
public :
  void	createWindows(int x, int y);
};

#endif
