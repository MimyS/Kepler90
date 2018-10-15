#include "Kepler90.h"

using namespace std;
GLfloat theta = 0.0f;

/**GLOBAL**/
GLfloat VisAngle;
GLfloat fAspect;

vector<Planet> LstPlanet = generatePlanets();

// Specify the virtual observer position
void ObserverPos() {
	// Coordinate system model
	glMatrixMode(GL_MODELVIEW);
	// Initialize system
	glLoadIdentity();
	// Specify observer and target position
	gluLookAt(0, 80, 10000, 0, 0, 0, 0, 1, 0);
}

void VisParamSpecify() {
	// Projection coordinate
	glMatrixMode(GL_PROJECTION);
	// Initialize projection coordinate system
	glLoadIdentity();
	// Specify projection type - perspective
	gluPerspective(VisAngle, fAspect, 0.5, 100000);

	ObserverPos();
}

void animate() {
	theta = theta + 0.05f;
	for (auto& p : LstPlanet) {
		p.updateinfos();
	}
	VisParamSpecify();
	glutPostRedisplay();
}

void windowReshapeFunc(GLsizei w, GLsizei h) {
	// Prevent division by 0
	if (h == 0) h = 1;
	// Viewport size
	glViewport(0, 0, w, h);
	// Aspect correction
	fAspect = (GLfloat)w / (GLfloat)h;

	VisParamSpecify();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(235/255.0, 183/255.0, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	glutWireSphere(695508/7000.0, 20, 20);
	glPopMatrix();

	for (auto& p : LstPlanet) {
		p.draw();
	}

	glutSwapBuffers();
};

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	default:
		break;
	}
}

void keyboard_special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	switch (state) {
	case GLUT_DOWN:
		switch (button) {
		case GLUT_LEFT_BUTTON:
		case GLUT_RIGHT_BUTTON:
		case GLUT_MIDDLE_BUTTON:
		default:
			break;
		}
	case GLUT_UP:
		switch (button) {
		case GLUT_LEFT_BUTTON:
		case GLUT_RIGHT_BUTTON:
		case GLUT_MIDDLE_BUTTON:
		default:
			break;
		}
	default:
		break;
	}
}