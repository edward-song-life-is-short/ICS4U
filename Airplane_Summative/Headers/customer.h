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
    string credit_card;
    Seat seat;

    public:
        Customer();
        Customer(string n, string p, string a, string c, Seat &s);
        Customer& operator=(const Customer&);

        void setSeat();
        
        string getAddress();
        string getName();
        string getPhone();
        Seat getSeat();
        string getCredit();

        

        void displayCustomer();
};  


#endif 