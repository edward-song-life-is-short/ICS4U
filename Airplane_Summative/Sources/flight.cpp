#include "../Headers/flight.h"
#include "../Headers/customer.h"
//basic flight from New York to LA that happens 9am every day 
Flight::Flight() {
    origin = "New York City";
    destination = "Los Angelos";
    plane = "Boeing 737";
    time = "9am";
    flight = 102343;

    initializeSeats();
}

void Flight::initializeSeats() {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            Seat *temp = new Seat(c, r+1);
            seatingPlan[r][c] = *temp;
        }
    }
}

Flight::Flight(int num, string plane, string o, string d, string t) {
    this->setFlightName(num);
    this->setPlane(plane);
    this->setLocation(o, d);
    this->setTime(t);

    initializeSeats();
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

    if(s.length() != 2 || (seatNum < 1 || seatNum > 5) || (letter != 'a' && letter != 'b' && letter != 'A' && letter != 'B')) {
        valid = false;
    }

    return valid;
    
}

int Flight::available = 10;

void Flight::logCustomer() {
    cout << "Congratulations on booking your seat.";
}
//book seat function0
void Flight::bookSeat() {
    bool valid = false;
    string newSeat;

    while(!valid) {
        cout << "Enter the seat you want to book" << endl;;

        cin >> newSeat;

        valid = readSeat(newSeat);
        break;
        cout << "Invalid Seat Number, Enter a valid seat:" << endl;
    }

    string seating;

    int local_r = newSeat[0] - '0' - 1;
    int local_c;

    if(newSeat[1] == 'A' || newSeat[1] == 'a') {
        local_c = 0;
    }
    else {
        local_c = 1;
    }

    if(!seatingPlan[local_r][local_c].getBooked()) {
        cout << "Your seat " << newSeat << " has been booked successfully." << endl << endl;
        seatingPlan[local_r][local_c].setBooked(true);
    }
    else {
        available--;
        cout << "This seat is not available." << endl;

        if(available > 0) {
        cout << "Here are the seats that are available:" << endl << endl;

        this->displaySeating();
        
        }
        else {
            cout << "There are not any other avaiable seats for this flight." << endl << endl;
        }

        bookSeat();
    }
    
}

void Flight::displaySeating() {
    cout << "Seating Plan for Flight " << flight << endl;
    
    Seat seat_d;

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            seat_d = seatingPlan[r][c];
            
            if(!seat_d.getBooked()) {
                cout << seat_d.getName() << "   ";
            }
            else {
                cout << "x    ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

Flight::~Flight() {}