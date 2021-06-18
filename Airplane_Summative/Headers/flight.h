#ifndef FLIGHT_H
#define FLIGHT_H


#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "customer.h"
#include "seat.h"

using namespace std;

class Flight
{
private:
     Seat seatingPlan[5][2];

     Customer passengerSeating[10];

     int available = 10;

     const string registeredPlanes[4] = {"Boeing 737", "Boeing 737Max", "Boeing 747-8", "Boeing 777x"};
     const string places[10] = {"New York City", "Los Angelos", "Houston", "Phoenix", "Nashville", "Kansas", "Nevada", "Austin", "Chicago", "Las Vegas"};

     string origin, destination;
     string plane;
     string time;
     int flight;

     vector<int> emptySeats;

     const int rows = 5;
     const int cols = 2;

     bool readSeat(string s);

     Customer passenger[10];
     
     static int flightNum;
     static int flightProfit;

public:
     Flight();
     Flight(int fl_name, string airP, string origin, string destination, string time);
     Flight(int, int, int, int);

     void intializePassArr();

     void setPlane(string p);
     void setTime(string t);
     void setFlightName(int f);
     void setLocation(string o, string d);

     void logCustomer(Seat&);
     void initializeSeats();

     void displaySeating();
     void bookSeat();
     void showAvailable();

     void cancel();
     void searchPassenger();
     
     void cancelFlight();

     void output();
     
     int returnFlight();
     string returnLocation();
     string returnTime();
     
     int returnFlightCash();

     void sortArray();
     void swapElements(Customer*, Customer*);

     Flight& operator =(const Flight&);

     ~Flight();
};

#endif