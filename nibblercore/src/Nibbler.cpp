#include "Nibbler.hpp"

Nibbler::Nibbler(int width, int height)
  : _width(width), _height(height), _game(Point2d<int>(width / 2, height / 2))
{
}

Nibbler::Nibbler()
  : _width(800), _height(600), _game(Point2d<int>(_width / 2, _height / 2))
{
}

Nibbler::~Nibbler()
{
}

void	Nibbler::setLib(void *lib)
{
  _external_creator = reinterpret_cast<IGui* (*)()>(dlsym(lib, "create_assistant"));
  if (_external_creator == NULL)
    throw nFault("Error with the shared lib\n");
}

void	Nibbler::run()
{
  IGui* gui = _external_creator();

  gui->createWindows(_width, _height);
}
