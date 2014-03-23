#ifndef DLLOADER_HPP_INCLUDED
#define DLLOADER_HPP_INCLUDED

#include <string>
#include <dlfcn.h>

#include "Fault.hpp"

template<typename T>
class DLLoader
{
public:
  DLLoader(const std::string& lib);
  ~DLLoader();

  T getInstance();

private:
  void* loadSym(const std::string& sym);
  void loadLib();

  std::string _libname;
  std::string _symbolname;
  bool _loaded;
  void* _handle;
};

#endif // DLLOADER_HPP_INCLUDED
