#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "seat.h"

class Customer {
    private:
        //customer information
        string phone;
        string name;
        string address;
        string credit_card;
        Seat seat;

    public:
        Customer();
        Customer(string n, string p, string a, string c, Seat &s); //parameterized constructor
        Customer& operator=(const Customer&); //overloading

        //mutator
        void setSeat();
        
        //accessor functions
        string getAddress();
        string getName();
        string getPhone();
        Seat getSeat();
        string getCredit();

        
        //show customer info
        void displayCustomer();

        ~Customer();
};  


#endif 