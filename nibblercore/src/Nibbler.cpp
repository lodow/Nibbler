#include "Nibbler.hpp"

Nibbler::Nibbler(const std::vector<std::string>& av)
{
  std::sstream ss;
  std::string lib;


  _win(win), _game(win / 2, win)

  _lib = new DLLoader<IGui*>(lib);
}

Nibbler::~Nibbler()
{
  delete _lib;
}
