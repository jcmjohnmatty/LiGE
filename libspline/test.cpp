#include <GL/glut.h>
#include "spline.hpp"

void
init_gl ()
{
  glEnable(GL_DEPTH_TEST);
  glClearColor(0,0,0,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(22.5, 1.0, 0.001, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void
draw_spline (void)
{
  // TODO Draw a spline.
}

void
my_display (void)
{
  // Clear all pixels, reset depth.
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glClearColor (0.0,0.0,0.0,1.0);

  gluLookAt (0,0,1, 0,0,-1, 0, 1, 0);

  // Draw spline.
  draw_spline ();

  glutSwapBuffers ();
}

void
my_reshape(int w, int h)
{
  glViewport(0, 0, w, h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(22.5, 1.0, 0.001, 100.0);

  glutPostRedisplay();
}

void
init_glut (int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Spline Test");

  glutDisplayFunc(my_display);
  glutReshapeFunc(my_reshape);

  init_gl ();
}

// Assume that argv[1] has filename to make life nicer.
int
main (int argc, char* argv[])
{
  init_glut (argc, argv);

  glutMainLoop ();

  return 0;
}
