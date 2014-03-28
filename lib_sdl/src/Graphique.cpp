#include "Graphique.hpp"

Graphique::Graphique()
{

}

Graphique::~Graphique()
{

}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::string	error;

  if ((SDL_Init(SDL_INIT_VIDEO) != 0)
      || ((_win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				   size.x(), size.y(), SDL_WINDOW_SHOWN)) == NULL)
      || ((_rend = SDL_CreateRenderer(_win, -1,SDL_RENDERER_ACCELERATED)) == NULL))
    {
      error = "Can't Init SDL: ";
      error += SDL_GetError();
      throw nFault(error, true);
    }
  SDL_RenderClear(_rend);
  SDL_RenderPresent(_rend);
}

//APPLE, SNAKE, WALL, EMPTY
void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  SDL_Rect	pos;

  (void) type;
  pos.x = square.getPos().x();
  pos.y = square.getPos().y();
  pos.w = square.getSize().w();
  pos.h = square.getSize().h();
  if (type == APPLE)
    SDL_SetRenderDrawColor(_rend, 0xFF, 0, 0, 0);
  else if (type == SNAKE)
    SDL_SetRenderDrawColor(_rend, 0xFF, 0xFF, 0xFF, 0x00);
  SDL_RenderDrawRect(_rend, &pos);
  SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0x00, 0x00);

}

void Graphique::clearScreen()
{
  static int	nb = 0;

  nb++;
  /*  if (nb%24 == 0)
    SDL_SetRenderDrawColor(_rend, 0x00, 0xFF, 0x00, 0x00);
  else if (nb%24 == 8)
    SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0xFF, 0x00);
  else if (nb%24 == 16)
  SDL_SetRenderDrawColor(_rend, 0xFF, 0x00, 0x00, 0x00);*/
  SDL_RenderClear(_rend);
}

void Graphique::drawScreen()
{
  SDL_RenderPresent(_rend);
}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  (void)pos;
  (void)text;
}

void Graphique::updateEvent(EventHandler& eventHandler)
{
  SDL_Event	event;
  char		fkey;

  while (SDL_PollEvent(&event))
    {
      if (event.window.event == SDL_WINDOWEVENT_CLOSE ||
	  (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
	fkey = 27;
      else if (event.type == SDL_KEYDOWN &&
	       (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP))
	fkey = 'z';
      else if (event.type == SDL_KEYDOWN &&
	       (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN))
	fkey = 's';
      else if (event.type == SDL_KEYDOWN &&
	       (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT))
	fkey = 'q';
      else if (event.type == SDL_KEYDOWN &&
	       (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT))
	fkey = 'd';
      eventHandler.addEvent(new Event(true, fkey));
    }
}
