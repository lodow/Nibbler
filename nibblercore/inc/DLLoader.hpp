#ifndef DLLOADER_HPP_INCLUDED
#define DLLOADER_HPP_INCLUDED

#include <string>

#include "Fault.hpp"

template<typename T>
class DLLoader
{
public:
  DLLoader(const std::string& lib);
  ~DLLoader();

  T* getInstance();


private:
  void loadLib();

  std::string _libname;
  bool _loaded;
};

#endif // DLLOADER_HPP_INCLUDED
