#ifndef VILLAN_H
#define VILLAN_H

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Villan {
	private:
		static int numOfVillans;
		bool infectious;
		int strength;
		string planet;
	
	public:
		Villan();
		Villan(int strength, string planet, bool infectious);

		Villan(const Villan& v);

		int getStrength();
		string getPlanet();
		bool getInfectious();
		void setStrength(int n);
		void setPlanet(string s);
		void setInfectious(bool b);

		string toString();

		Villan& operator=(const Villan &v);

		void addStrength(int value);
		void subtractStrength(int value);
		void strengthUp(const Villan& v);
		void reduce(const Villan& v);

		static Villan& create(Villan v, Villan v2);

		static Villan& multiply(Villan v1, Villan v2);	

		~Villan();

};

#endif