#include "../Headers/flight.h"

//basic flight from New York to LA that happens 9am every day 
Flight::Flight() {
    origin = "New York City";
    destination = "Los Angelos";
    plane = "Boeing 737";
    time = "9am";
    flight = 102343;
}

Flight::Flight(int num, string plane, string o, string d, string t) {
    this->setFlightName(num);
    this->setPlane(plane);
    this->setLocation(o, d);
    this->setTime(t);
}

void Flight::setFlightName(int id) {
    stringstream id_str;
    id_str << id;
    if(id_str.str().length() == 6) {
        this->flight = id;
    }
    else {
        this->flight = 0;
    }
}

void Flight::setPlane(string p) {
    int pl_arr_size = 

    for(int i = 0; i < )
}

