#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

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
  virtual void	updateEvent(EventHandler& eventHandler);
  virtual void	clearScreen();
  virtual void	drawScreen();

  void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

private:
  std::map<blockType, std::vector<unsigned char> > _colorMap;
  Point2d<int>	_winsize;
  void*	_mlx;
  void*	_win;
  void*	_screen;
  int*	_screenptr;
  int	_linesize;
};

#endif
