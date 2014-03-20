#include "DLLoader.hpp"
#include "IGui.hpp"

template<typename T>
DLLoader<T>::DLLoader(const std::string& lib)
{
  _libname = lib;
  _loaded = false;
}

template<typename T>
DLLoader<T>::~DLLoader()
{
}

template<typename T>
T DLLoader<T>::getInstance()
{
  if (!_loaded)
    loadLib();

  return (NULL);
}

template<typename T>
void DLLoader<T>::loadLib()
{
  _loaded = true;
}

template class DLLoader<IGui*>;
