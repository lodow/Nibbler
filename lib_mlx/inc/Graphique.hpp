#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

#include <iostream>
#include <cstdlib>

#include "IGui.hpp"
#include "Fault.hpp"

class Graphique : public IGui
{
public:
  Graphique();
  virtual ~Graphique();

  virtual void	createWindows(const Point2d<int>& size);
  virtual void	drawSquare(const Box<int>& square, blockType type);
  virtual void	affText(const Point2d<int>& pos, const std::stringstream& text);
  virtual bool	getEvent(eventType event);
  virtual void	clearScreen();
  virtual void	drawScreen();

private:
  Point2d<int>	_winsize;
  void*	_mlx;
  void*	_win;
  void*	_screen;
  void*	_screenbuffer;
};

#endif
