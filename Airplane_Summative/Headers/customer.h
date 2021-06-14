#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "seat.h"

class Customer {
    private:
        
    string phone;
    string name;
    string address;
    Seat seat;

    public:
        Customer();
        Customer(string n, string p, string a, Seat &s);
        Customer& operator=(const Customer&);

        void setSeat();
        
        string getAddress();
        string getName();
        string getPhone();
        Seat getSeat();

        

        void displayCustomer();
};  


#endif 