#include "Kepler90Models.h"

vector<Planet> generatePlanets() {

	string Names[] = {"Kepler90b", "Kepler90c", "Kepler90i", "Kepler90d", "Kepler90e", "Kepler90f", "Kepler90g", "Kepler90h"};
	string Types[] = {"Super Earth", "Super Earth", "Super Earth", "Neptune-like", "Neptune-like", "Neptune-like", "Gas Giant", "Gas Giant"};
	double Radius[] = { 1.31*6371, 1.19*6371, 1.32*6371, 0.256*69911, 0.237*69911, 0.257*69911, 0.723*69911, 1.008*69911 };
	float OrbRads[] = { 0.074, 0.089, 0.15, 0.32, 0.42, 0.48, 0.71, 1.01 };
	float OrbPer[] = { 7, 8.7, 14.4, 59.7, 91.9, 124.9, 210.6, 331.6 };
	int datas[] = { 2013, 2013, 2017, 2013, 2013, 2013, 2013, 2013 };
	struct PlanetColor color[] = {
		{129 / 255.0, 72 / 255.0, 232 / 255.0}, {47 / 255.0, 232 / 255.0, 187 / 255.0}, {176 / 255.0, 50 / 255.0, 162 / 255.0} ,
		{49 / 255.0, 181 / 255.0, 47 / 255.0}, {47 / 255.0, 193 / 255.0, 255 / 255.0}, {237 / 255.0, 203 / 255.0, 138 / 255.0} ,
		{195 / 255.0, 65 / 255.0, 4 / 255.0}, {186 / 255.0, 21 / 255.0, 13 / 255.0}
	};
	
	vector<Planet> KeplerPlanets;

	Planet temp = Planet();

	for (char i = 0; i < 8; i++) {
		temp.Name = Names[i];
		temp.Type = Types[i];
		temp.Radius = Radius[i];
		temp.OrbitalPeriod = OrbPer[i];
		temp.OrbitalRadius = OrbRads[i];
		temp.DiscoveryDate = datas[i];
		temp.color = color[i];
		temp.translateDeg = 0;
		temp.rotateDeg = 0;
		KeplerPlanets.push_back(temp);
	}

	return KeplerPlanets;
}

void Planet::draw() {
	glPushMatrix();
	
	glRotatef(translateDeg, 0.0f, 0.0f, 1.0f);

	GLfloat temp = (OrbitalRadius * 149600000) / (15*7000.0);
	glTranslated(temp, 0, 0);

	glRotatef(rotateDeg, 0.0f, 0.0f, 1.0f);
	
	glColor3f(color.Red, color.Green, color.Blue);
	glutWireSphere(Radius / 7000.0, 25, 25);
	glPopMatrix();
}

void Planet::updateinfos() {
	translateDeg += 1/OrbitalPeriod;
	rotateDeg += 0.01;
}
