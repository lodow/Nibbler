#include <iostream>
#include "Nibbler.hpp"

int main(int argc, char **argv)
{
  Nibbler nib;
  void *dlhandle;

  if (argc != 4)
    {
      std::cout << "Usage : ./nibbler <libXXX.so>" << std::endl;
      return (1);
    }
  dlhandle = dlopen(argv[1], RTLD_LAZY);
  if (dlhandle == NULL)
    {
      std::cerr << "Error opening '" << argv[1] << "'" << std::endl;
      std::cerr << dlerror() << std::endl;
      return(1);
    }
  try
    {
      nib.setLib(dlhandle);
      nib.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (1);
    }
  dlclose(dlhandle);
  return (0);
}
