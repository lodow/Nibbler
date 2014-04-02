#include "Graphique.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <GL/freeglut_ext.h>

#include "EventHandling.hpp"

int		key;

void		pressed_key(unsigned char k, int x, int y)
{
  (void)x;
  (void)y;
  key = k;
}

void		pressed_key_arrow(int k, int x, int y)
{
  (void)x;
  (void)y;
  key = k;
}

Graphique::Graphique()
{
  int		i = 1;

  glutInit(&i, NULL);
}

Graphique::~Graphique()
{
}

void Graphique::createWindows(const Point2d<int>& size)
{
  _win = size;
  glutInitWindowSize(size.x(), size.y());
  glutInitWindowPosition(50, 50);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Snake_GL");
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  Point2d<double>  tmp = square.getSize();

  tmp /= (_win / 2.0);
  glPushMatrix();
  if (type == APPLE)
    glColor3d(0, 181, 96);
  else if (type == SNAKE)
    glColor3d(181, 96, 0);
  else if (type == HEAD)
    glColor3d(96, 0, 181);
  glTranslatef(((static_cast<double>(square.getPos().x())) / _win.x() - 0.5) * 2.0,
	       (((static_cast<double>(square.getPos().y()))) / _win.y() - 0.5) * 2.0, 0.0);
  glRectf(0, 0, tmp.w(), tmp.h());
  glPopMatrix();
}

void Graphique::clearScreen()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphique::drawScreen()
{
  glutSwapBuffers();
}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  (void)pos;
  (void)text;
}

void Graphique::updateEvent(EventHandler& eventHandler)
{
  EventType ev;

  glutMainLoopEvent();
  glutPostRedisplay();
  glutKeyboardUpFunc(pressed_key);
  glutKeyboardFunc(pressed_key);
  glutSpecialFunc(pressed_key_arrow);
  if (key == 27)
    ev = QUIT;
  else if (key == 'z' || key == GLUT_KEY_DOWN)
    ev = UP;
  else if (key == 's' || key == GLUT_KEY_UP)
    ev = DOWN;
  else if (key == 'q' || key == GLUT_KEY_LEFT)
    ev = LEFT;
  else if (key == 'd' || key == GLUT_KEY_RIGHT)
    ev = RIGHT;
  else if (key == 'o')
    {
      ev = CHANGELIB;
      eventHandler.addEvent(new Event(false, ev));
      return ;
    }
  eventHandler.addEvent(new Event(true, ev));
}
