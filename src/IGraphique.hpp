/*
** IGraphique.hpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 16:15:15 2014 Maxime
** Last update Wed Mar 12 16:51:07 2014 Maxime
*/

#ifndef IGRAPHIQUE_HPP_
#define IGRAPHIQUE_HPP_

class IGraphique
{
public :
  virtual ~IGraphique() {};
public :
  virtual void	createWindows(int x, int y) = 0;
};

#endif
