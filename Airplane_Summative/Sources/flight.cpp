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
    for(int i = 0; i < 6; i++) {
        if(registeredPlanes[i].compare(p) == 0) {
            plane = p;
            break;
        }
    }

    plane = "Invalid";
}

void Flight::setLocation(string o, string d) {
    if(o.compare(d)) {
        origin = "Invalid";
        destination = "Invalid";
        return;
    }
    
    bool ori = false;
    int de = false;

    for(int i = 0; i < 10; i++) {
        if(places[i].compare(o)) {
            origin = o;
            ori = true;
        }

        if(places[i].compare(d)) {
            destination = d;
            de = true;
        }
    }

    if(!ori) {
        origin = "Invalid";
    }

    if(!de) {
        destination = "Invalid";
    }
    
}

void Flight::setTime(string t) {
    if((int) t[0] >= 0 && (int) t[0] <= 24 && t.length() == 2) {

    }

}