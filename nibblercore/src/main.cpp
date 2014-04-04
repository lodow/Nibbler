#include <iostream>
#include <string>
#include <vector>

#include "Fault.hpp"
#include "Nibbler.hpp"

int main(int argc, char **argv)
{
  std::vector<std::string> av;
  std::vector<std::string> libslist;
  Nibbler* nib;

  nib = NULL;
  try
    {
      srand(time(NULL));
      libslist.push_back("lib_nibbler_mlx.so");
      libslist.push_back("lib_nibbler_sdl.so");
      libslist.push_back("lib_nibbler_opengl.so");
      for (int i = 0; i < argc; i++)
        av.push_back(std::string(argv[i]));
      nib = new Nibbler(av, libslist);
      nib->run();
      delete nib;
    }
  catch (std::exception& e)
    {
      delete nib;
      std::cerr << e.what() << std::endl;
      return (1);
    }
  return (0);
}
