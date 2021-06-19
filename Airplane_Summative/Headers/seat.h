#ifndef SEAT_H
#define SEAT_H 

#include <iostream>
#include <string>
using namespace std;

class Seat {
    private:
        //seat info
        int row, col;
        string name;
        bool booked;
        bool business;

        //seat string info
        const string econPerks[3] = {"in-flight entertainment", "leather seats", "beverage refreshments"};
        const string busiPerks[3] = {"larger entertainment screens", "fully-reclinable seats", "full meal course"};

        //prices
        const int econPrice = 800;
        const int busiPrice = 1200;

        const int perkSize = 3;

    public:
        Seat();
        Seat(int x, int y);
        Seat& operator=(const Seat& copy); //operator overloading
        
        
        //accessor functions
        string getName();
        int getRow();
        int getCol();
        bool getBooked();
        bool returnBusiness();
        int returnPrice();
        
        //mutators
        void setBusiness(bool b);
        void setBooked(bool v);

        void displayPerks();

        ~Seat();

        

};

#endif