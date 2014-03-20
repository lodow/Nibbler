#include <iostream>
#include <string>
#include <vector>

#include "Nibbler.hpp"

int main(int argc, char **argv)
{
  std::vector<std::string> av;
  Nibbler* nib;

  for (int i = 0; i < argc; i++)
    av.push_back(std::string(argv[i]));

  nib = new Nibbler(av);


  /* if (argc != 4)
     {
       std::cout << "Usage : ./nibbler <width> <height> <libXXX.so>" << std::endl;
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
   dlclose(dlhandle);*/
  delete nib;
  return (0);
}
