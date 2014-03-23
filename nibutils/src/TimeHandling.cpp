#include "TimeHandling.hpp"

TimeHandler::TimeHandler(float fps)
{
  setFps(fps);
  _fps = 0.0;
  _frames = 0;
}

TimeHandler::~TimeHandler()
{
}

void TimeHandler::setFps(float fps)
{
  if (fps == 0.0)
    fps = 1.0;
  _targetFps = fps;
}

void TimeHandler::startFrame()
{
  _start = clock();
}

void TimeHandler::endFrame()
{
  _end = clock();
  _frames += 1;
}

float TimeHandler::getElapsedTime() const
{
  return (((float)(_end - _start)) / CLOCKS_PER_SEC);
}

void TimeHandler::alignOnFps()
{
  float elapsed;
  struct timespec req;

  elapsed = getElapsedTime();
  if (elapsed < 1 / _targetFps)
    {
      req.tv_sec = 0;
      req.tv_nsec = elapsed * 1000000000.0;
      nanosleep(&req, NULL);
      _fps = _targetFps;
    }
  else
    _fps = 1 / elapsed;
}
