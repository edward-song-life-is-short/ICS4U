#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Flight
{
private:
     string seatingPlan[5][2] = {
         {"1a", "1b"},
         {"2a", "2b"},
         {"3a", "3b"},
         {"4a", "4b"},
         {"5a", "5b"}};

     const string registeredPlanes[10] = {"Boeing 737", "Boeing 737Max", "Boeing 747-8", "Boeing 777x"};
     const string places[6] = {"New York City", "Los Angelos", "Houston", "Phoenix", "Nashville", "Kansas"};

     string origin, destination;
     string plane;
     string time;
     int flight;

     const int rows = 5;
     const int cols = 2;

     bool readSeat(string s);
     bool checkSeat(string s);

public:
     Flight();
     Flight(int fl_name, string airP, string origin, string destination, string time);

     void setPlane(string p);
     void setTime(string t);
     void setFlightName(int f);
     void setLocation(string o, string d);

     void bookSeat(string s);

     void output();

     ~Flight();
};