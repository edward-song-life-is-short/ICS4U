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
     //seating plan for flight
     Seat seatingPlan[5][2];

     //customer and seats
     Customer passengerSeating[10];

     //available seats
     int available = 10;

     //const info arrays
     const string registeredPlanes[4] = {"Boeing 737", "Boeing 737Max", "Boeing 747-8", "Boeing 777x"};
     const string places[10] = {"New York City", "Los Angelos", "Houston", "Phoenix", "Nashville", "Kansas", "Nevada", "Austin", "Chicago", "Las Vegas"};

     //flight info
     string origin, destination;
     string plane;
     string time;
     int flight;

     //fixed seating plan of rows and columns 
     const int rows = 5;
     const int cols = 2;

     //convert string of 1A to row and col position
     bool readSeat(string s);

     Customer passenger[10];
     
     //static vars
     static int flightNum;
     static int flightProfit;
     static bool testVar;

public:
     Flight();
     Flight(int fl_name, string airP, string origin, string destination, string time); //param constructor
     Flight(int, int, int, int); //random generator constructor 

     //initialize empty customers and seats
     void intializePassArr();
     void initializeSeats();

     //mutators
     void setPlane(string p);
     void setTime(string t);
     void setFlightName(int f);
     void setLocation(string o, string d);
     void setTestVar(bool v);

     //store customer info
     void logCustomer(Seat&);
     
     //seating functions
     void displaySeating();
     void bookSeat();
     void showAvailable();

     //cancel Seat
     void cancel();

     void searchPassenger();
     
     void cancelFlight();

     void output();

     //accessors 
     int returnFlight();
     string returnLocation();
     string returnTime();
     int returnFlightCash();

     //sort seating array so that customers organized by seat
     void sortArray();

     //used in the sort
     void swapElements(Customer*, Customer*);

     Flight& operator =(const Flight&); //overloading

     ~Flight();
};

#endif