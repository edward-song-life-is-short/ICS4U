#include "../Headers/seat.h"

Seat::Seat() {
    row = 0;
    col = 0;

    booked = false;
    name = "N/A";
}

//find seat info
Seat::Seat(int x, int y) {
    col = x;
    row = y;
    int output_row = y+1;

    booked = false;

    string letter;

    if(col == 0) {
        letter = "A";
    }
    else {
        letter = "B";
    }

    //generat names of all the seats 
    name = to_string(output_row) + letter; 
}

Seat& Seat::operator=(const Seat&other) {
    row = other.row;
    col = other.col;
    booked = other.booked;
    name = other.name;
    business = other.business;
    return *this;
}

string Seat::getName() {
    return name;    
}

bool Seat::getBooked() {
    return booked;
}

void Seat::setBooked(bool v) {
    booked = v;
}

void Seat::setBusiness(bool b) {
    business = b;
}

bool Seat::returnBusiness(){
    return business;
}

int Seat::getCol() {
    return col;
}

int Seat::getRow() {
    return row;
}

int Seat::returnPrice() {
    if(business) {
        return busiPrice;
    }
    else {
        return econPrice;
    }
}

void Seat::displayPerks() {
    cout << "The features offered by this seat:" << endl;
    
    //output features
    for(int i = 0; i < perkSize; i++) {
        if(business) {
            cout << busiPerks[i] << ", ";
        }
        else {
            cout << econPerks[i] << ", ";
        }
    }

    cout << endl;
}

Seat::~Seat() {}