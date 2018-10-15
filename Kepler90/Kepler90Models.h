#ifndef KEPLER90MODELS_HEADER
#define KEPLER90MODELS_HEADER

#include<GL/glut.h>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

struct PlanetColor {
	GLfloat Red, Green, Blue;
};

class Planet {
public:
	Planet() {};
	~Planet() {};
	int DiscoveryDate;
	float OrbitalPeriod;
	float OrbitalRadius;
	double Radius;
	GLfloat translateDeg;
	GLfloat rotateDeg;
	struct PlanetColor color;
	string Type;
	string Name;
	void draw();
	void updateinfos();
private:
};

vector<Planet> generatePlanets();

#endif
