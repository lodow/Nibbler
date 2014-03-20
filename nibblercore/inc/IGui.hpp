#ifndef IGUI_HPP_
#define IGUI_HPP_

#include <iostream>
#include <sstream>
#include <string>

typedef enum {HEAD_SNAKE, QUEU_SNAKE, WALL, EMPTY} blockType;
typedef enum {UPKEY, DOWNKEY, LEFTKEY, RIGHTKEY, ESCAPEKEY, F5KEY} eventType;

class IGui
{
public :
  virtual ~IGui() {};

  virtual void	createWindows(int x, int y) = 0;
  virtual void	drawSquare(int x, int y, int w, int h, blockType type) = 0;
  virtual void	affText(int x, int y, const std::stringstream& text) = 0;
  virtual bool	getEvent(eventType event) = 0;
};

#endif
