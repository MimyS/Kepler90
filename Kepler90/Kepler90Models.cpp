#include "Kepler90Models.h"

using namespace std;

class Planet {
public:
	Planet() {};
	~Planet() {};
	int DiscoveryDate;
	float OrbitalPeriod;
	float OrbitalRadius;
	double Radius;
	string Type;
	string Name;
	void draw();
private:
};

vector<Planet> generatePlanets() {

	string Names[] = {"Kepler90b", "Kepler90c", "Kepler90i", "Kepler90d", "Kepler90e", "Kepler90f", "Kepler90g", "Kepler90h"};
	string Types[] = {"Super Earth", "Super Earth", "Super Earth", "Neptune-like", "Neptune-like", "Neptune-like", "Gas Giant", "Gas Giant"};
	double Radius[] = { 1.31*6.371, 1.19*6.371, 1.32*6.371, 0.256*69.911, 0.237*69.911, 0.257*69.911, 0.723*69.911, 1.008*69.911 };
	float OrbRads[] = { 0.074, 0.089, 0, 0.32, 0.42, 0.48, 0.71, 1.01 };
	float OrbPer[] = { 7, 8.7, 14.4, 59.7, 91.9, 124.9, 210.6, 331.6 };
	int datas[] = { 2013, 2013, 2017, 2013, 2013, 2013, 2013, 2013 };
	
	vector<Planet> KeplerPlanets;

	Planet temp = Planet();

	for (char i = 0; i < 8; i++) {
		temp.Name = Names[i];
		temp.Type = Types[i];
		temp.Radius = Radius[i];
		temp.OrbitalPeriod = OrbPer[i];
		temp.OrbitalRadius = OrbRads[i];
		temp.DiscoveryDate = datas[i];
		KeplerPlanets.push_back(temp);
	}

	return KeplerPlanets;
}

void Planet::draw() {
	/*Draw WireSphere*/
}
