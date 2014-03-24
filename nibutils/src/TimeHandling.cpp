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

  elapsed = getElapsedTime();
  if (elapsed < 1.0 / _targetFps)
    {
      usleep(((1.0 / _targetFps) - elapsed) * 1000000);
      _fps = _targetFps;
    }
  else
    _fps = 1 / elapsed;
}
