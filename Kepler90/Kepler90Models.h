#ifndef KEPLER90MODELS_HEADER
#define KEPLER90MODELS_HEADER

#include<GL/glut.h>
#include<iostream>
#include<utility>
#include<vector>
#include <ctime>

#define ORBIT_SCALE (15*7000.0)
#define PLANET_SCALE (7000.0)
#define TIME_SCALE 200

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
	void updateinfos(double);
private:
};

double Tick();

vector<Planet> generatePlanets();

#endif
