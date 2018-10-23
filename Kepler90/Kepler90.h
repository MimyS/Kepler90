#ifndef KEPLER_HEADER
#define KEPLER_HEADER

#include "Kepler90Models.h"
#include "ViewClass.h"
#include "ControlClass.h"

/**GLOBAL**/
extern ViewClass viewC;
extern ControlClass control;

void keyboard(unsigned char key, int x, int y);

void keyboard_special(int key, int x, int y);

void mouse(int button, int state, int x, int y);

void drawScene();

void animate();

void windowReshapeFunc(GLsizei w, GLsizei h);

#endif