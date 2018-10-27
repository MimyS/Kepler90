#include "Kepler90.h"

using namespace std;
GLfloat theta = 0.0f;

/**GLOBAL**/
ViewClass viewC;
ControlClass control;

vector<Planet> LstPlanet = generatePlanets();

void animate() {
	double time = Tick();
	if (time < 0.01)
		time = 0.01;

	theta += time * 0.02f;
	for (auto& p : LstPlanet) {
		p.updateinfos(time);
	}

	viewC.VisParamSpecify();
	glutPostRedisplay();
}

void windowReshapeFunc(GLsizei w, GLsizei h) {
	viewC.windowReshape(w, h);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(235/255.0, 183/255.0, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	glutWireSphere(695508/(PLANET_SCALE*3), 20, 20);
	glPopMatrix();

	for (auto& p : LstPlanet) {
		p.draw();
	}

	glutSwapBuffers();
};

void keyboard(unsigned char key, int x, int y) {
	control.keyboard(key, x, y, viewC, LstPlanet);
}

void keyboard_special(int key, int x, int y) {
	control.keyboard_special(key, x, y, viewC);
}

void mouse(int button, int state, int x, int y) {
	control.mouse(button, state, x, y, viewC);
}