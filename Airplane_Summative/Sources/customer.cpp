#include "../Headers/flight.h"

Customer::Customer() {
    name = "N/A";
    phone = "N/A";
    address = "N/A";
    credit_card = "N/A";
}

Customer::Customer(string n, string p, string a, string c, Seat &s) {
    name = n;
    phone = p;
    address = a;
    seat = s;
    credit_card = c;

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

string Customer::getCredit() {
    return credit_card;
}

Customer& Customer::operator=(const Customer& copy) {
    name = copy.name;
    phone = copy.phone;
    address = copy.address;
    seat = copy.seat;
    credit_card = copy.credit_card;

    return *this;
}

Customer::~Customer() {}