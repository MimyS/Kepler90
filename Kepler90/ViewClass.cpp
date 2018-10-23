#include "ViewClass.h"

using namespace std;

ViewClass::ViewClass() {
	cameraX = 0;
	cameraY = 80;
	cameraZ = 2000;
	centerX = 0;
	centerY = 0;
	centerZ = 0;
	viewUpX = 0;
	viewUpY = 1;
	viewUpZ = 0;
	visAngle = 50;
	fAspect = 0;
}


ViewClass::~ViewClass() {
}

// Specify the virtual observer position
void ViewClass::ObserverPos() {
	// Coordinate system model
	glMatrixMode(GL_MODELVIEW);
	// Initialize system
	glLoadIdentity();
	// Specify observer and target position
	gluLookAt(cameraX, cameraY, cameraZ, centerX, centerY, centerZ, viewUpX, viewUpY, viewUpZ);
}

void ViewClass::VisParamSpecify() {
	// Projection coordinate
	glMatrixMode(GL_PROJECTION);
	// Initialize projection coordinate system
	glLoadIdentity();
	// Specify projection type - perspective
	gluPerspective(visAngle, fAspect, 0.5, 100000);

	ObserverPos();
}

void ViewClass::windowReshape(GLsizei w, GLsizei h) {
	// Prevent division by 0
	if (h == 0) h = 1;
	// Viewport size
	glViewport(0, 0, w, h);
	// Aspect correction
	fAspect = (GLfloat)w / (GLfloat)h;

	VisParamSpecify();
}

void ViewClass::MoveCenterX(int val) {
	centerX += val;
}

void ViewClass::MoveCenterY(int val) {
	centerY += val;
}

void ViewClass::MoveCenterZ(int val) {
	centerZ += val;
}

void ViewClass::MoveCameraX(int val) {
	cameraX += val;
}

void ViewClass::MoveCameraY(int val) {
	cameraY += val;
}

void ViewClass::MoveCameraZ(int val) {
	cameraZ += val;
}

void ViewClass::MoveViewUpX(int val) {
	viewUpX += val;
}

void ViewClass::MoveViewUpY(int val) {
	viewUpY += val;
}

void ViewClass::MoveViewUpZ(int val) {
	viewUpZ += val;
}

void ViewClass::SetCameraPos(GLfloat x, GLfloat y, GLfloat z) {
	cameraX = x;
	cameraY = y;
	cameraZ = z;
}

void ViewClass::ResetViewUp() {
	viewUpX = 0;
	viewUpY = 1;
	viewUpZ = 0;
}

void ViewClass::ResetCenter() {
	centerX = 0;
	centerY = 0;
	centerZ = 0;
}

void ViewClass::ZoomIn() {
	// prevent visAngle from reaching 0
	if (visAngle > 1) {
		visAngle -= 1;
	} else if (visAngle > 0.25) {
		visAngle -= 0.1;
	} else if (visAngle > 0.01) {
		visAngle -= 0.01;
	}
}

void ViewClass::ZoomOut() {
	// prevent visAngle from reaching 180
	if (visAngle < 179) {
		visAngle += 1;
	} else if (visAngle < 179.75) {
		visAngle += 0.1;
	} else if (visAngle < 179.99) {
		visAngle += 0.01;
	}
}
