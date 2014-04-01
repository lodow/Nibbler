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
  Box<double>	tmp = square;

  //tmp.getPos() = (tmp.getPos() / _win);
  glPushMatrix();
  if (type == APPLE)
    glColor3d(0, 181, 96);
  else if (type == SNAKE)
    glColor3d(181, 96, 0);
  else if (type == HEAD)
    glColor3d(96, 0, 181);
  glTranslatef(((double)square.getPos().x()) / _win.x(), ((double)square.getPos().y()) / _win.y(), 0);
  glRectf(tmp.getPos().x(), tmp.getSize().y(),
          tmp.getPos().x() + tmp.getSize().w(),
          tmp.getPos().y() + tmp.getSize().h());
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
  glutMainLoopEvent();
  glutPostRedisplay();
  glutKeyboardFunc(pressed_key);
  glutSpecialFunc(pressed_key_arrow);
  if (key == 27)
    _ev = QUIT;
  else if (key == 'z' || key == GLUT_KEY_DOWN)
    _ev = UP;
  else if (key == 's' || key == GLUT_KEY_UP)
    _ev = DOWN;
  else if (key == 'q' || key == GLUT_KEY_LEFT)
    _ev = LEFT;
  else if (key == 'd' || key == GLUT_KEY_RIGHT)
    _ev = RIGHT;
  else if (key == 'o')
    _ev = CHANGELIB;
  eventHandler.addEvent(new Event(true, _ev));
}
