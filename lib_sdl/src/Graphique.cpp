#include "Graphique.hpp"

Graphique::Graphique()
{
  std::string	error;

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      error = "Can't Init SDL: ";
      error += SDL_GetError();
      throw nFault(error, true);
    }
  _colorMap[APPLE].push_back(0);
  _colorMap[APPLE].push_back(255);
  _colorMap[APPLE].push_back(0);

  _colorMap[SNAKE].push_back(128);
  _colorMap[SNAKE].push_back(128);
  _colorMap[SNAKE].push_back(0);

  _colorMap[HEAD].push_back(128);
  _colorMap[HEAD].push_back(0);
  _colorMap[HEAD].push_back(128);

  _colorMap[WALL].push_back(255);
  _colorMap[WALL].push_back(0);
  _colorMap[WALL].push_back(0);

  _colorMap[TELEP].push_back(255);
  _colorMap[TELEP].push_back(0);
  _colorMap[TELEP].push_back(255);

  _colorMap[EMPTY].push_back(0);
  _colorMap[EMPTY].push_back(0);
  _colorMap[EMPTY].push_back(0);
}

Graphique::~Graphique()
{
  SDL_DestroyRenderer(_rend);
  SDL_DestroyWindow(_win);
}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::string	error;

  if (((_win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                size.x(), size.y(), SDL_WINDOW_SHOWN)) == NULL)
      || ((_rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED)) == NULL))
    {
      error = "SDL can't create window: ";
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

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  SDL_Rect	pos;

  std::vector<unsigned char>& colors = _colorMap.at(type);
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
  else if (type == SNAKE)
    {
      if (_timer > 150)
	SDL_RenderCopy(_rend, _texSnake2, NULL, &pos);
      else
	SDL_RenderCopy(_rend, _texSnake, NULL, &pos);
    }
  else if (type == HEAD)
    {
      if (_timer > 150)
	SDL_RenderCopy(_rend, _texHead2, NULL, &pos);
      else
	SDL_RenderCopy(_rend, _texHead, NULL, &pos);
    }
  else
    {
      SDL_SetRenderDrawColor(_rend, colors[0], colors[1], colors[2], 0x00);
      SDL_RenderDrawRect(_rend, &pos);
    }
}

void Graphique::clearScreen()
{
  _timer++;
  if (_timer == 300)
    _timer = 0;
  SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0x00, 0x00);
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
  EventType	ev;

  while (SDL_PollEvent(&event))
    {
      ev = NONE;
      if (event.window.event == SDL_WINDOWEVENT_CLOSE)
        eventHandler.addEvent(new Event(true, ev));
      else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
          if (event.key.keysym.sym == SDLK_ESCAPE)
            ev = QUIT;
          else if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
            ev = UP;
          else if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
            ev = DOWN;
          else if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
            ev = LEFT;
          else if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
            ev = RIGHT;
          else if (event.key.keysym.sym == SDLK_o)
            ev = CHANGELIB;
          eventHandler.addEvent(new Event((event.type == SDL_KEYDOWN ? true : false), ev));
        }
    }
}
