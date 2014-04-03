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
  TTF_Quit();
}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::string	error;
  SDL_Texture	*tmp;


  if (((_win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                size.x(), size.y(), SDL_WINDOW_SHOWN)) == NULL)
      || ((_rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED)) == NULL))
    {
      error = "SDL can't create window: ";
      error += SDL_GetError();
      throw nFault(error, true);
    }
  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == -1)
    throw nFault(IMG_GetError(), true);
  if (TTF_Init() == -1)
    throw nFault(IMG_GetError(), true);

  error = "SDL can't load texture: ";

  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/corp.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[SNAKE].push_back(tmp);
  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/_corp.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[SNAKE].push_back(tmp);

  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/apple.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[APPLE].push_back(tmp);
  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/_apple.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[APPLE].push_back(tmp);

  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/head.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[HEAD].push_back(tmp);
  if ((tmp = IMG_LoadTexture(_rend, "./lib_sdl/res/_head.png")) == NULL)
    throw nFault(error + SDL_GetError(), true);
  _texMap[HEAD].push_back(tmp);

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
  if (type == APPLE || type == SNAKE || type == HEAD)
    SDL_RenderCopy(_rend, _texMap[type][(_timer > 150)], NULL, &pos);
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
  /*Point2d<int> pos;
  std::stringstream t;

    t << "5";
  pos.x() = 5;
  pos.y() = 5;
  this->affText(pos, t);
  */ SDL_RenderPresent(_rend);

}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  TTF_Font      *font;
  std::string	error;
  SDL_Color     color;
  SDL_Texture   *texture;
  SDL_Surface   *text_surface;
  SDL_Rect      rec;
  int w, h;

  error = "Font error :";
  color.r = 0xFF;
  color.g = 0xFF;
  color.b = 0xFF;
  if (!(font = TTF_OpenFont("./lib_sdl/res/frenchy.ttf", 100)))
    {
    throw nFault(TTF_GetError(), true);
    }
  if (!(text_surface = TTF_RenderText_Blended(font, text.str().c_str(), color)))
    throw nFault(error + TTF_GetError(), true);
  if (!(texture = SDL_CreateTextureFromSurface(_rend, text_surface)))
    throw nFault(error + TTF_GetError(), true);
  SDL_FreeSurface(text_surface);
  TTF_CloseFont(font);
  rec.x = pos.x();
  rec.y = pos.y();
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  rec.w = w;
  rec.h = h;
  SDL_RenderCopy(_rend, texture, NULL, &rec);
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
          else if (event.key.keysym.sym == SDLK_p)
            ev = PAUSE;
          else if (event.key.keysym.sym == SDLK_RETURN)
            ev = ENTER;
          eventHandler.addEvent(new Event((event.type == SDL_KEYDOWN ? true : false), ev));
        }
    }
}
