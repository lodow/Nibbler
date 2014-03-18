/*
** IGraphique.hpp for nibbler in /home/maxime/projet/actu/cpp_nibbler
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Wed Mar 12 16:15:15 2014 Maxime
** Last update Tue Mar 18 22:34:22 2014 Maxime
*/

#ifndef IGUI_HPP_
#define IGUI_HPP_

#include <iostream>
#include <sstream>
#include <string>

typedef enum {SNAKE, HEAD_SNAKE, QUEU_SNAKE, OBJECT, EMPTY} blockType;
typedef enum {TOP, BUTTON, LEFT, RIGHT, ESCAPE, F5} eventType;


class IGui
{
public :
  virtual ~IGui() {};
public :
  virtual void	createWindows(int x, int y) = 0;
  virtual void	drawSquare(int x, int y, blockType type) = 0;
  virtual void	gameOver() = 0;
  virtual void	affTexte(int x, int y, std::stringstream const  &text, int lenght) = 0;
  virtual bool	getEvent(eventType event);
};

#endif
