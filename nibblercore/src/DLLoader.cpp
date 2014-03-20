#include "DLLoader.hpp"
#include "IGui.hpp"

template<typename T>
DLLoader<T>::DLLoader(const std::string& lib)
{
  _libname = std::string("./") + lib;
  _handle = NULL;
  _loaded = false;
  _symbolname = "instance";
}

template<typename T>
DLLoader<T>::~DLLoader()
{
  char* err;

  if (_loaded)
    if (dlclose(_handle))
      {
        err = dlerror();
        throw nFault(std::string("Can't close library: ") + err, false);
      }
}

template<typename T>
T DLLoader<T>::getInstance()
{
  void* sym;
  T (*func)();

  sym = loadSym(_symbolname);
  func = reinterpret_cast<T (*)()>(sym);
  return (func());
}

template<typename T>
void DLLoader<T>::loadLib()
{
  char* err;

  _handle = dlopen(_libname.c_str(), RTLD_LAZY);
  if (_handle == NULL)
    {
      err = dlerror();
      throw nFault(std::string("Can't load library: ") + err, false);
    }
  _loaded = true;
}

template<typename T>
void* DLLoader<T>::loadSym(const std::string& symbolname)
{
  void* sym;
  char* err;

  if (!_loaded)
    loadLib();
  dlerror();
  sym = dlsym(_handle, symbolname.c_str());
  if (sym == NULL && (err = dlerror()) == NULL)
    throw nFault(std::string("Can't get symbol: ") + err, false);
  return (sym);
}

template class DLLoader<IGui*>;

