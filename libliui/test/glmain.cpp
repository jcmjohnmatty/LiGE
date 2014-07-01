#include <GL/glut.h>
#include "../button.hpp"
#include "../color.hpp"
#include "glmain.hpp"

int
main (int argc, char* argv[])
{
  glutInit (&argc, argv);

  init_gl ();
  my_init ();

  glutMainLoop ();

  return 0;
}

void
my_init ()
{
}

void
init_gl ()
{
  glClearColor (0, 0, 0, 1);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0, 1, 0, 1);

  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

  glutInitWindowSize (500, 500);
  glutInitWindowPosition (0, 0);
  glutCreateWindow ("libliui test");

  glutDisplayFunc (my_display);
  glutReshapeFunc (resize_window);
  glutIdleFunc (idle);
}

void
idle ()
{
}

void
my_display ()
{
  color fgc;
  color bgc;

  fgc.r = bgc.r = fgc.g = bgc.g = fgc.b = bgc.b = fgc.a = bgc.a = 1;

  li::button b (fgc, bgc);
  glClear (GL_COLOR_BUFFER_BIT);

  glColor3f (1, 1, 1);
  b.draw ();

  glutSwapBuffers ();
}

void
resize_window (int w, int h)
{
  glViewport (0, 0, w, h);
}
