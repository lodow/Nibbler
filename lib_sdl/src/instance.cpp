#include "Graphique.hpp"

extern "C"
{
  IGui* instance()
  {
    return new Graphique();
  }
}
