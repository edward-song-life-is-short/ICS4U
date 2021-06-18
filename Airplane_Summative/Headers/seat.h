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
        bool business;

        string econPerks[3] = {"in-flight entertainment", "leather seats", "beverage refreshments"};
        string busiPerks[3] = {"larger entertainment screens", "fully-reclinable seats", "full meal course"};

        const int econPrice = 800;
        const int busiPrice = 1200;

        const int perkSize = 3;

    public:
        Seat();
        Seat(int x, int y);
        Seat& operator=(const Seat& copy);
        string getName();
        
        
        int getRow();
        int getCol();

        bool getBooked();
        void setBooked(bool v);
        
        bool returnBusiness();
        void setBusiness(bool b);

        void displayPerks();

        int returnPrice();

};

#endif