#include "Graphique.hpp"

#include <cstdlib>

#include "mlx_int.h"
#include "mlx.h"

int mlx_keypressed_hook(void *tmp, int (*funct)(), void *param)
{
  t_win_list *win = static_cast<t_win_list*>(tmp);

  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
  return (0);
}

int pressed_key(int key, void *arg)
{
  std::map<unsigned int, bool>* mkey;

  mkey = static_cast<std::map<unsigned int, bool>* >(arg);
  (*mkey)[key] = true;
  return (0);
}

int realesed_key(int key, void *arg)
{
  std::map<unsigned int, bool>* mkey;

  mkey = static_cast<std::map<unsigned int, bool>* >(arg);
  (*mkey)[key] = false;
  return (0);
}

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
  mlx_key_hook(_win, reinterpret_cast<int (*)()>(&realesed_key), &_keys);
  mlx_keypressed_hook(_win, reinterpret_cast<int (*)()>(&pressed_key), &_keys);
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  (void)type;
  if ((square.getPos().x() >= 0 && square.getPos().x() + square.getSize().w() < _winsize.x())
      && (square.getPos().y() >= 0 && square.getPos().y() + square.getSize().h() < _winsize.y()))
    for (int j = square.getPos().y(); j < square.getSize().h() + square.getPos().y(); j++)
      for (int i = square.getPos().x(); i < square.getSize().w() + square.getPos().x(); i++)
        putPixel(i, j, 255, 0, 0);
}

void Graphique::clearScreen()
{
  for (int j = 0; j < _winsize.h(); j++)
    for (int i = 0; i < _winsize.w(); i++)
      putPixel(i, j, 0, 0, 0);
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

void Graphique::updateEvent(EventHandler& eventHandler)
{
}

void Graphique::putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
  unsigned int color;

  color = r << 16 | g << 8 | b;
  color = mlx_get_color_value(_mlx, color);
  _screenptr[y * _linesize + x] = color;
}

