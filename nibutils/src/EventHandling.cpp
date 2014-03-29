#include "EventHandling.hpp"

Event::Event(bool down, EventType event)
  : _down(down), _event(event)
{

}

Event::~Event()
{

}

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::addEvent(Event* ev)
{
  _events.push_back(ev);
}

bool EventHandler::pollEvent(Event& ev)
{
  Event* tmp;

  if (_events.size() <= 0)
    return (false);
  tmp = _events.front();
  _events.pop_front();
  ev = *tmp;
  delete tmp;
  return (true);
}


