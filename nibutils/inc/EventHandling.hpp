#ifndef EVENTHANDLING_HPP_INCLUDED
#define EVENTHANDLING_HPP_INCLUDED

#include <list>

class AEvent
{
  AEvent();
  ~AEvent();

};

class EventHandler
{
public:
  EventHandler();
  ~EventHandler();

private:
  std::list<AEvent*> _events;
};

#endif // EVENTHANDLING_HPP_INCLUDED
