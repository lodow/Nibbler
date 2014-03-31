#include "Graphique.hpp"

Graphique::Graphique()
{

}

Graphique::~Graphique()
{
  SDL_DestroyRenderer(_rend);
  SDL_DestroyWindow(_win);
}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::string	error;

  if ((SDL_Init(SDL_INIT_VIDEO) != 0)
      || ((_win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   size.x(), size.y(), SDL_WINDOW_SHOWN)) == NULL)
      || ((_rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED)) == NULL))
    {
      error = "Can't Init SDL: ";
      error += SDL_GetError();
      throw nFault(error, true);
    }
  _texSnake = IMG_LoadTexture(_rend, "./lib_sdl/res/corp.png");
  _texApple = IMG_LoadTexture(_rend, "./lib_sdl/res/apple.png");
  _texHead = IMG_LoadTexture(_rend, "./lib_sdl/res/head.png");

  _texSnake2 = IMG_LoadTexture(_rend, "./lib_sdl/res/_corp.png");
  _texApple2 = IMG_LoadTexture(_rend, "./lib_sdl/res/_apple.png");
  _texHead2 = IMG_LoadTexture(_rend, "./lib_sdl/res/_head.png");

  if (_texSnake == NULL || _texApple == NULL
      || _texSnake2 == NULL || _texApple2 == NULL)
    {
      error = "Can't load texture: ";
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
    {
      if (_timer > 150)
	SDL_RenderCopy(_rend, _texApple2, NULL, &pos);
      else
	SDL_RenderCopy(_rend, _texApple, NULL, &pos);
    }
  else if (type == SNAKE && _nb != 0)
    {
      //SDL_SetRenderDrawColor(_rend, 0xFF, 0xFF, 0xFF, 0x00);
      if (_timer > 150)
	SDL_RenderCopy(_rend, _texSnake2, NULL, &pos);
      else
	SDL_RenderCopy(_rend, _texSnake, NULL, &pos);
    }
  else if (type == SNAKE && _nb == 0)
    {
      if (_timer > 150)
	SDL_RenderCopy(_rend, _texHead2, NULL, &pos);
      else
	SDL_RenderCopy(_rend, _texHead, NULL, &pos);
      _nb++;
    }
  else
    {
      SDL_SetRenderDrawColor(_rend, 0xFF, 0, 0, 0);
      SDL_RenderDrawRect(_rend, &pos);
      SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0x00, 0x00);
    }
}

void Graphique::clearScreen()
{
  _nb = 0;
  _timer++;
  if (_timer == 300)
    _timer = 0;
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
      fkey = '\0';
      if (event.window.event == SDL_WINDOWEVENT_CLOSE)
	eventHandler.addEvent(new Event(true, fkey));
      else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    fkey = 27;
	  else if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
	    fkey = 'z';
	  else if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
	    fkey = 's';
	  else if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
	    fkey = 'q';
	  else if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
	    fkey = 'd';
	  else if (event.key.keysym.sym == SDLK_o)
	    fkey = 'o';
	  eventHandler.addEvent(new Event((event.type == SDL_KEYDOWN ? true : false), fkey));
	}
    }
}
