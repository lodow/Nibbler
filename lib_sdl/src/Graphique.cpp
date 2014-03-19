/*
** Graphique.cpp for pi in /home/maxime/projet/actu/cpp_nibbler/src_sdl
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 15:17:33 2014 Maxime
** Last update Wed Mar 12 16:27:13 2014 Maxime
*/

#include "Graphique.hpp"

Graphique::Graphique()
{

}

Graphique::~Graphique()
{

}

void Graphique::createWindows(int x, int y)
{
  std::cout << "Mmmh, Tu veux créer une fenetre de " << x << " par " << y << " ?\nBen non !\n";
}

extern "C"
{
  IGraphique* create_assistant()
  {
    return new Graphique();
  }
}
