#ifndef EVENTHANDLING_HPP_INCLUDED
#define EVENTHANDLING_HPP_INCLUDED

#include <list>

typedef enum {NONE, UP, DOWN, RIGHT, LEFT, QUIT, CHANGELIB, PAUSE} EventType;

class Event
{
public:
  Event(bool down = false, EventType key = NONE);
  ~Event();

  bool getDown() const {return _down;};
  EventType getEvent() const {return _event;};
private:
  bool _down;
  EventType _event;
};

class EventHandler
{
public:
  EventHandler();
  ~EventHandler();

  void addEvent(Event* ev);
  bool pollEvent(Event& ev);

private:
  std::list<Event*> _events;
};

#endif // EVENTHANDLING_HPP_INCLUDED
