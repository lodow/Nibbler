#include "Graphique.hpp"

#include "mlx.h"
#include <cstdlib>

Graphique::Graphique()
{
  _mlx = mlx_init();
  if (_mlx == NULL)
    throw nFault("Can't init mlx", true);
  _win = NULL;
}

Graphique::~Graphique()
{
  if (_win)
    mlx_destroy_window(_mlx, _win);
  free(_mlx);
}

void Graphique::createWindows(const Point2d<int>& size)
{
  _winsize = size;
  _win = mlx_new_window(_mlx, size.x(), size.y(), const_cast<char*>("Nibbler"));
  if (_win == NULL)
    throw nFault("mlx: Failed to create a new windows", true);
  _screen = mlx_new_image(_mlx, size.x(), size.y());
  if (_screen == NULL)
    throw nFault("mlx: Failed to create a new image", true);
  _screenbuffer = mlx_new_image(_mlx, size.x(), size.y());
  if (_screenbuffer == NULL)
    throw nFault("mlx: Failed to create a new image", true);
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  (void)square;
  (void)type;
}

void Graphique::clearScreen()
{

}

void Graphique::drawScreen()
{

}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  (void)pos;
  (void)text;
}

bool Graphique::getEvent(eventType event)
{
  (void)event;
  return (false);
}

