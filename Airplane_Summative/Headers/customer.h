#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
    private:
        
    string phone;
    string name;
    string address;
    string seat;

    public:
        Customer();
        Customer(string p, string n, string a, string s);
        
        void setSeat();
        
        void displayCustomer();
};  


#endif 