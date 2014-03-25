#ifndef EVENTHANDLING_HPP_INCLUDED
#define EVENTHANDLING_HPP_INCLUDED

#include <list>

class Event
{
public:
  Event(bool down = false, char key = '\0');
  ~Event();

  bool getDown() const {return _down;};
  char getKey() const {return _key;};
private:
  bool _down;
  char _key;
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
