#include "Graphique.hpp"

Graphique::Graphique()
{

}

Graphique::~Graphique()
{

}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::cout << "Mmmh, Tu veux créer une fenetre de " << size.x() << " par " << size.y() << " ?\nBen non !\n";
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  (void)square;
  (void)type;
}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  (void)pos;
  (void)text;
}

bool Graphique::getEvent(eventType event)
{
  (void)event;
  return (false);
}
