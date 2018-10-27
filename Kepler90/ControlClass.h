#ifndef CONTROLCLASS_HEADER
#define CONTROLCLASS_HEADER

#include"ViewClass.h"
#include"Kepler90Models.h"
#include<GL/glut.h>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

class ControlClass {
	int lstX;
	int lstY;

public:
	void keyboard(unsigned char, int, int, ViewClass &, vector<Planet> &);
	void keyboard_special(int, int, int, ViewClass &);
	void mouse(int, int, int, int, ViewClass &);
	ControlClass();
	~ControlClass();
};

#endif