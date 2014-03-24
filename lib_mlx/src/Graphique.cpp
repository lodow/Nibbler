#include "Graphique.hpp"

#include "mlx.h"
#include <cstdlib>

Graphique::Graphique()
{
  _mlx = mlx_init();
  if (_mlx == NULL)
    throw nFault("Can't init mlx", true);
  _win = NULL;
  _screen = NULL;
}

Graphique::~Graphique()
{
  if (_win)
    mlx_destroy_window(_mlx, _win);
  free(_mlx);
}

void Graphique::createWindows(const Point2d<int>& size)
{
  int bpp;
  int endian;
  int linesize;

  _winsize = size;
  _win = mlx_new_window(_mlx, size.x(), size.y(), const_cast<char*>("Nibbler"));
  if (_win == NULL)
    throw nFault("mlx: Failed to create a new windows", true);
  _screen = mlx_new_image(_mlx, size.x(), size.y());
  if (_screen == NULL)
    throw nFault("mlx: Failed to create a new image", true);
  _screenptr = reinterpret_cast<int*>(mlx_get_data_addr(_screen, &bpp, &linesize, &endian));
  if (!_screenptr || bpp != 32 || endian)
    throw nFault("mlx: Doesn't handle those type of X buffers", true);
  _linesize = linesize / (32 / 8);
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  (void)type;
  std::cout << "box: x: " << square.getPos().x() << " y: " << square.getPos().y() << " w: " << square.getSize().h() << " h: " << square.getSize().h() << std::endl;
  if ((square.getPos().x() >= 0 && square.getPos().x() + square.getSize().w() < _winsize.x())
      && (square.getPos().y() >= 0 && square.getPos().y() + square.getSize().h() < _winsize.y()))
    for (int j = square.getPos().y(); j < square.getSize().h(); j++)
      for (int i = square.getPos().x(); i < square.getSize().w(); i++)
        putPixel(i, j, 255, 0, 0);
}

void Graphique::clearScreen()
{
  for (int j = 0; j < _winsize.h(); j++)
    for (int i = 0; i < _winsize.w(); i++)
      putPixel(i, j, 0, 128, 0);
}

void Graphique::drawScreen()
{
  mlx_put_image_to_window(_mlx, _win, _screen, 0, 0);
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

void Graphique::putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
  unsigned int color;

  color = r << 16 | g << 8 | b;
  color = mlx_get_color_value(_mlx, color);
  _screenptr[y * _linesize + x] = color;
}
