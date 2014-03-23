#ifndef IGUI_HPP_
#define IGUI_HPP_

#include <iostream>
#include <sstream>
#include <string>

#include "Box.hpp"
#include "Point2d.hpp"

typedef enum {HEAD_SNAKE, QUEU_SNAKE, WALL, EMPTY} blockType;
typedef enum {UPKEY, DOWNKEY, LEFTKEY, RIGHTKEY, ESCAPEKEY, F5KEY} eventType;

class IGui
{
public:
  virtual ~IGui() {};

  virtual void	createWindows(const Point2d<int>& size) = 0;
  virtual void	drawSquare(const Box<int>& square, blockType type) = 0;
  virtual void	affText(const Point2d<int>& pos, const std::stringstream& text) = 0;
  virtual bool	getEvent(eventType event) = 0;
  virtual void	clearScreen() = 0;
  virtual void	drawScreen() = 0;
};

#endif
