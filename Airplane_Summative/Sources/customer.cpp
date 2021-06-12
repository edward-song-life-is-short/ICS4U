#include "../Headers/flight.h"

Customer::Customer() {
    name = "N/A";
    phone = "N/A";
    address = "N/A";
    seat = "N/A";
}

Customer::Customer(string n, string p, string a, string s) {
    name = n;
    phone = n;
    address = a;
    seat = s;

}

void Customer::displayCustomer() {
    cout << "Name:" << name << endl;
    cout << "Telephone:" << phone << endl;
    cout << "Address:" << address << endl;
    cout << "Seat:" << seat << endl;
}
