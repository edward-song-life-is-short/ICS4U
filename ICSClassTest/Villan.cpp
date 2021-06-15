#include "Villan.h"

int Villan::numOfVillans = 0;

Villan::Villan() {
	strength = 0;
	infectious = 0;
	planet = "Earth";

	numOfVillans++;
}

Villan::Villan(int s, string p, bool i) {
	strength = s;
	planet = p;
	infectious = i;

	numOfVillans++;
}

Villan::Villan(const Villan &v) {
	strength = v.strength;
	planet = v.planet;
	infectious = v.infectious;

	numOfVillans++;
}

int Villan::getStrength() {
	return strength;
}

string Villan::getPlanet() {
	return planet;
}

bool Villan::getInfectious() {
	return infectious;
}

void Villan::setPlanet(string p) {
	planet = p;
}

void Villan::setStrength(int n) {
	strength = n;
}

void Villan::setInfectious(bool b) {
	infectious = b;
}

string Villan::toString() {
	stringstream s;
	
	s << "Strength: " << strength << endl;
	s << "Planet: "  << planet << endl;
	s << "Infectious Bool: " << infectious << endl << endl;

	return s.str();
}

Villan& Villan::operator=(const Villan &v) {
	strength = v.strength;
	planet = v.planet;
	infectious = v.infectious;

	return *this;
}

void Villan::addStrength(int value) {
	strength += value;
}

void Villan::subtractStrength(int value) {
	strength -= value;
}

void Villan::strengthUp(const Villan &v) {
	strength += v.strength;
}

void Villan::reduce(const Villan &v) {
	strength -= v.strength;
}

Villan& Villan::create(Villan v1, Villan v2) {
	bool same;
	int newS;

	if(v1.infectious == v2.infectious) {
		same = v1.infectious;
		newS = v1.strength + v2.strength;
	} else {
		if(v1.strength>v2.strength) {
			same = v1.infectious;
			newS = v1.strength-v2.strength;
		}
		else {
			same = v2.infectious;
			newS = v2.strength-v1.strength;
		}

	}
	
	Villan *newGuy = new Villan(newS, "?", same);
	return *newGuy;
}

Villan::~Villan() {}


//multiply their strengths together
//new villain is instantly infectious
// planet jupiter
Villan& Villan::multiply(Villan v1, Villan v2) {
	int s = v1.strength * v2.strength;
	
	Villan *newGuy = new Villan(s, "Jupiter", true);

	return *newGuy;
}

