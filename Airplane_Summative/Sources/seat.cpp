#include "../Headers/seat.h"

Seat::Seat() {
    row = 0;
    col = 0;

    booked = false;
    name = "N/A";
}

Seat::Seat(int x, int y) {
    col = x;
    row = y;

    booked = false;

    string letter;

    if(col == 0) {
        letter = "A";
    }
    else {
        letter = "B";
    }

    name = to_string(row) + letter; 
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