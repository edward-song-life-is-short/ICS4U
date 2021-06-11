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
            return;
        }
    }

    plane = "Invalid";
}

void Flight::setLocation(string o, string d) {
    if(!o.compare(d)) {
        origin = "Invalid";
        destination = "Invalid";
        cout << "same";
        return;
    }
    
    bool ori = false;
    int de = false;

    for(int i = 0; i < 10; i++) {
        if(!places[i].compare(o)) {
            origin = o;
            ori = true;
        }

        if(!places[i].compare(d)) {
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
    // string str = t.substr(1,2);
    
    // int num = t[0] - '0';
    // cout << num;

    // if(num >= 0 && num <= 24 && t.length() == 3 && (str.compare("am") == 0 || str.compare("pm"))) {
    //     time = t;
    // }
    // else {
    //     time = "Invalid";
    // }

    time = t;

}

void Flight::output() {
    cout << "Flight Summary" << endl << endl;
    
    cout << "Flight Number:" << flight << endl;
    
    
    if(!origin.compare("Invalid") && !destination.compare("Invalid"))
        cout << "Origin to Destination:" << origin << " to " << destination << endl;
    else 
        cout << "Origin to destination: Invalid" << endl;
    
    cout << "Flight Time:" << time << endl;
    cout << "Plane:" << plane << endl;

    cout << endl;
}

bool Flight::readSeat(string s) {
    bool valid = true;
    //seat check

    int seatNum = s[0] - '0';

    char letter = s[1];

    if(s.length() != 2 || (seatNum < 1 || seatNum > 5) || (letter != 'a' && letter != 'b') ) {
        valid = false;
    }

    return valid;
    
}

//book seat function0
void Flight::bookSeat(string s) {
    bool v;
    
    v = readSeat(s);
    string newSeat = s;

    
    while(!v) {
        cout << "Invalid Seat Number, Enter a valid seat:" << endl;
        cin >> newSeat;

        v = readSeat(newSeat);
    }

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if(!seatingPlan[r][c].compare(newSeat)) { //if the seat is found
                seatingPlan[r][c] = "x"; 
                cout << "Your seat " << newSeat << " has been booked successfully." << endl;
                return;
            }
        }
    }

    cout << "This seat is not available." << endl;
    

}

Flight::~Flight() {}