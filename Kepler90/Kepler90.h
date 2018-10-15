#ifndef KEPLER_HEADER
#define KEPLER_HEADER

#include "Kepler90Models.h"

/**GLOBAL**/
extern GLfloat VisAngle, fAspect;

void keyboard(unsigned char key, int x, int y);

void keyboard_special(int key, int x, int y);

void mouse(int button, int state, int x, int y);

void drawScene();

void animate();

void windowReshapeFunc(GLsizei w, GLsizei h);

#endif