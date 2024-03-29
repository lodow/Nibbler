#include "Graphique.hpp"

#include <cstdlib>

#include "EventHandling.hpp"
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
  EventHandler* handler;
  EventType ev;

  ev = NONE;
  handler = static_cast<EventHandler*>(arg);
  if (key == 65307)
    ev = QUIT;
  else if (key == 65362 || key == 122)
    ev = UP;
  else if (key == 65364 || key == 115)
    ev = DOWN;
  else if (key == 65363 || key == 100)
    ev = RIGHT;
  else if (key == 65361 || key == 113)
    ev = LEFT;
  else if (key == 111)
    ev = CHANGELIB;
  else if (key == 112)
    ev = PAUSE;
  else if (key == 65293)
    ev = ENTER;
  handler->addEvent(new Event(true, ev));
  return (0);
}

int realesed_key(int key, void *arg)
{
  EventType ev;
  EventHandler* handler;

  ev = NONE;
  handler = static_cast<EventHandler*>(arg);
  if (key == 65307)
    ev = QUIT;
  else if (key == 65362 || key == 122)
    ev = UP;
  else if (key == 65364 || key == 115)
    ev = DOWN;
  else if (key == 65363 || key == 100)
    ev = RIGHT;
  else if (key == 65361 || key == 113)
    ev = LEFT;
  else if (key == 111)
    ev = CHANGELIB;
  else if (key == 112)
    ev = PAUSE;
  else if (key == 65293)
    ev = ENTER;
  handler->addEvent(new Event(false, ev));
  return (0);
}

Graphique::Graphique()
{
  _mlx = mlx_init();
  if (_mlx == NULL)
    throw nFault("Can't init mlx", true);
  _win = NULL;
  _screen = NULL;
  _colorMap[APPLE].push_back(0);
  _colorMap[APPLE].push_back(255);
  _colorMap[APPLE].push_back(0);

  _colorMap[SNAKE].push_back(128);
  _colorMap[SNAKE].push_back(128);
  _colorMap[SNAKE].push_back(0);

  _colorMap[HEAD].push_back(128);
  _colorMap[HEAD].push_back(0);
  _colorMap[HEAD].push_back(128);

  _colorMap[WALL].push_back(255);
  _colorMap[WALL].push_back(0);
  _colorMap[WALL].push_back(0);

  _colorMap[TELEP].push_back(255);
  _colorMap[TELEP].push_back(0);
  _colorMap[TELEP].push_back(255);

  _colorMap[EMPTY].push_back(0);
  _colorMap[EMPTY].push_back(0);
  _colorMap[EMPTY].push_back(0);
}

Graphique::~Graphique()
{
  if (_win)
    {
      mlx_key_hook(_win, NULL, NULL);
      mlx_keypressed_hook(_win, NULL, NULL);
      mlx_destroy_window(_mlx, _win);
      mlx_event(_mlx);
    }
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
  const std::vector<unsigned char>& colors = _colorMap.at(type);
  if ((square.getPos().x() >= 0 && square.getPos().x() + square.getSize().w() <= _winsize.x())
      && (square.getPos().y() >= 0 && square.getPos().y() + square.getSize().h() <= _winsize.y()))
    for (int j = square.getPos().y(); j < square.getSize().h() + square.getPos().y(); j++)
      for (int i = square.getPos().x(); i < square.getSize().w() + square.getPos().x(); i++)
        putPixel(i, j, colors[0], colors[1], colors[2]);
}

void Graphique::clearScreen()
{
  drawSquare(Box<int>(Point2d<int>(0, 0), _winsize), EMPTY);
}

void Graphique::drawScreen()
{
  mlx_put_image_to_window(_mlx, _win, _screen, 0, 0);
}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  mlx_string_put(_mlx, _win, pos.x(), pos.y(), 0x00FFFFFF, const_cast<char*>(text.str().c_str()));
}

void Graphique::updateEvent(EventHandler& eventHandler)
{
  mlx_key_hook(_win, reinterpret_cast<int (*)()>(&realesed_key), &eventHandler);
  mlx_keypressed_hook(_win, reinterpret_cast<int (*)()>(&pressed_key), &eventHandler);
  mlx_event(_mlx);
}

void Graphique::putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
  unsigned int color;

  color = r << 16 | g << 8 | b;
  color = mlx_get_color_value(_mlx, color);
  _screenptr[y * _linesize + x] = color;
}
