#include "Graphique.hpp"

Graphique::Graphique()
{

}

Graphique::~Graphique()
{

}

void Graphique::createWindows(int x, int y)
{
  std::cout << "Mmmh, Tu veux créer une fenetre de " << x << " par " << y << " ?\nBen non !\n";
}

void Graphique::drawSquare(int x, int y, blockType type)
{
  (void)x;
  (void)y;
  (void)type;
}

void Graphique::affText(int x, int y, const std::stringstream& text)
{
  (void)x;
  (void)y;
  (void)text;
}

bool Graphique::getEvent(eventType event)
{
  (void)event;
  return (false);
}
