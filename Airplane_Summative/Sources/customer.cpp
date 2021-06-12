#include "../Headers/flight.h"

Customer::Customer() {
    name = "N/A";
    phone = "N/A";
    address = "N/A";
}

Customer::Customer(string n, string p, string a, Seat &s) {
    name = n;
    phone = n;
    address = a;
    seat = s;

}

void Customer::displayCustomer() {
    cout << "Name:" << name << endl;
    cout << "Telephone:" << phone << endl;
    cout << "Address:" << address << endl;
    cout << "Seat:" << seat.getName() << endl;
}

string Customer::getName() {
    return name;
}

string Customer::getAddress() {
    return address;
}

string Customer::getPhone() {
    return phone;
}

Seat Customer::getSeat() {
    return seat;
}

Customer::Customer(const Customer& copy) {
    name = copy.name;
    phone = copy.phone;
    address = copy.address;
    seat = copy.seat;
}