#ifndef SEAT_H
#define SEAT_H 

#include <iostream>
#include <string>
using namespace std;

class Seat {
    private:
        int row, col;
        string name;
        bool booked;


    public:
        Seat();
        Seat(int x, int y);
        string getName();
        
        bool getBooked();
        void setBooked(bool v);


};

#endif