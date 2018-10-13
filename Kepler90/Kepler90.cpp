#include "Kepler90.h"

using namespace std;

void drawScene() {

	//gluLookAt(); -- define ponto de referencia para visualização
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