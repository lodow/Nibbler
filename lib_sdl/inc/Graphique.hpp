#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

#include <iostream>
#include "IGui.hpp"

class Graphique : public IGui
{
public :
  Graphique();
  virtual ~Graphique();
public :
  virtual void	createWindows(int x, int y);
  virtual void	drawSquare(int x, int y, blockType type);
  virtual void	affText(int x, int y, const std::stringstream& text);
  virtual bool	getEvent(eventType event);
};

#endif
