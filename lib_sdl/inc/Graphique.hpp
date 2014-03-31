#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <vector>

#include "IGui.hpp"

class Graphique : public IGui
{
public:
  Graphique();
  virtual ~Graphique();

  virtual void	createWindows(const Point2d<int>& size);
  virtual void	drawSquare(const Box<int>& square, blockType type);
  virtual void	affText(const Point2d<int>& pos, const std::stringstream& text);
  virtual void	updateEvent(EventHandler& eventHandler);
  virtual void	clearScreen();
  virtual void	drawScreen();
private:
  std::map<blockType, std::vector<unsigned char> > _colorMap;
  SDL_Window	*_win;
  SDL_Renderer	*_rend;
  SDL_Texture	*_texSnake;
  SDL_Texture	*_texApple;
  SDL_Texture	*_texHead;
  SDL_Texture	*_texSnake2;
  SDL_Texture	*_texApple2;
  SDL_Texture	*_texHead2;
  int		_nb;
  int		_timer;
};

#endif
