#ifndef FLIGHT_H
#define FLIGHT_H


#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "customer.h"
#include "seat.h"

using namespace std;

class Flight
{
private:
     Seat seatingPlan[5][2];
     Customer passengerSeating[10];

     static int available;

     const string registeredPlanes[10] = {"Boeing 737", "Boeing 737Max", "Boeing 747-8", "Boeing 777x"};
     const string places[6] = {"New York City", "Los Angelos", "Houston", "Phoenix", "Nashville", "Kansas"};

     string origin, destination;
     string plane;
     string time;
     int flight;

     vector<int> emptySeats;

     const int rows = 5;
     const int cols = 2;

     bool readSeat(string s);

     Customer passenger[10];
     

public:
     Flight();
     Flight(int fl_name, string airP, string origin, string destination, string time);

     void setPlane(string p);
     void setTime(string t);
     void setFlightName(int f);
     void setLocation(string o, string d);

     void logCustomer(Seat);
     void initializeSeats();

     void displaySeating();
     void bookSeat();
     void showAvailable();

     void cancel();
     void searchPassenger();
     
     void output();

     ~Flight();
};

#endif