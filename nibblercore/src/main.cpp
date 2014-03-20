#include <iostream>
#include <string>
#include <vector>

#include "Fault.hpp"
#include "Nibbler.hpp"

int main(int argc, char **argv)
{
  std::vector<std::string> av;
  Nibbler* nib;

  nib = NULL;
  try
    {
      for (int i = 0; i < argc; i++)
        av.push_back(std::string(argv[i]));
      nib = new Nibbler(av);
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
