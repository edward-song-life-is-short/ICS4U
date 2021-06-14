#include "../Headers/flight.h"
#include "../Headers/customer.h"
//basic flight from New York to LA that happens 9am every day
Flight::Flight()
{
    origin = "New York City";
    destination = "Los Angelos";
    plane = "Boeing 737";
    time = "9am";
    flight = 102343;

    initializeSeats();
}

void Flight::initializeSeats()
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            Seat *temp = new Seat(c, r);
            seatingPlan[r][c] = *temp;
        }
    }
}


Flight::Flight(int num, string plane, string o, string d, string t)
{
    this->setFlightName(num);
    this->setPlane(plane);
    this->setLocation(o, d);
    this->setTime(t);

    initializeSeats();
    intializePassArr();
}

void Flight::intializePassArr() {
    //create an empty set of passengers in the array
    for(int i = 0; i < 10; i++) {
        Customer *empty = new Customer();
        passenger[i] = *empty;
    }
    
}

void Flight::setFlightName(int id)
{
    stringstream id_str;
    id_str << id;
    if (id_str.str().length() == 6)
    {
        this->flight = id;
    }
    else
    {
        this->flight = 0;
    }
}

void Flight::setPlane(string p)
{
    for (int i = 0; i < 6; i++)
    {
        if (registeredPlanes[i].compare(p) == 0)
        {
            plane = p;
            return;
        }
    }

    plane = "Invalid";
}

void Flight::setLocation(string o, string d)
{
    if (!o.compare(d))
    {
        origin = "Invalid";
        destination = "Invalid";
        cout << "same";
        return;
    }

    bool ori = false;
    int de = false;

    for (int i = 0; i < 10; i++)
    {
        if (!places[i].compare(o))
        {
            origin = o;
            ori = true;
        }

        if (!places[i].compare(d))
        {
            destination = d;
            de = true;
        }
    }

    if (!ori)
    {
        origin = "Invalid";
    }

    if (!de)
    {
        destination = "Invalid";
    }
}

void Flight::setTime(string t)
{
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

void Flight::output()
{
    cout << "Flight Summary" << endl
         << endl;

    cout << "Flight Number:" << flight << endl;

    if (!origin.compare("Invalid") && !destination.compare("Invalid"))
        cout << "Origin to Destination:" << origin << " to " << destination << endl;
    else
        cout << "Origin to destination: Invalid" << endl;

    cout << "Flight Time:" << time << endl;
    cout << "Plane:" << plane << endl;

    cout << endl;
}

bool Flight::readSeat(string s)
{
    bool valid = true;
    //seat check

    int seatNum = s[0] - '0';

    char letter = s[1];

    if (s.length() != 2 || (seatNum < 1 || seatNum > 5) || (letter != 'a' && letter != 'b' && letter != 'A' && letter != 'B'))
    {
        valid = false;
    }

    return valid;
}

int Flight::available = 10;

void Flight::logCustomer(Seat s)
{
    cout << "Congratulations on booking your seat. We need to log some of your personal information:" << endl;
    
    string info[3];
    string l;

    // cout << "Enter your name:" << endl;
    // cin >> info[0];
    // cout << "Enter your phone number:" << endl;
    // cin >> info[1];

    // cout << "Enter your address:" << endl;
    // cin >> info[2];

    info[0] = "1";
    info[1] = "2";
    info[2] = "3";

    Customer *temp = new Customer(info[0], info[1], info[2], s);
    passengerSeating[available] = *temp;

    // temp->displayCustomer();

    delete temp;
}
//book seat function
void Flight::bookSeat()
{
    bool valid;
    string newSeat;
    int exit = 1;

    valid = false;
    while (!valid)
    {
        cout << "Enter the seat you want to book:" << endl;

        cin >> newSeat;

        valid = readSeat(newSeat);
        
        if(valid) {
            break;
        }
        
        cout << "Invalid Seat Number, Enter a valid seat:" << endl;
    }

    int local_r = newSeat[0] - '0' - 1;
    int local_c;

    if (newSeat[1] == 'A' || newSeat[1] == 'a')
    {
        local_c = 0;
    }
    else
    {
        local_c = 1;
    }

    if (!seatingPlan[local_r][local_c].getBooked())
    {
        cout << "Your seat " << newSeat << " has been booked successfully." << endl
             << endl;
        
        seatingPlan[local_r][local_c].setBooked(true);

        valid = false;

        available--;

        logCustomer(seatingPlan[local_r][local_c]);

    }
    else
    {
        cout << "This seat is not available." << endl;

        if (available > 0)
        {
            cout << "Here are the seats that are available:" << endl << endl;

            this->displaySeating();

            cout << "Book another seat:" << endl;
            bookSeat();
        }
        else
        {
            cout << "There are not any other avaiable seats for this flight. Enter 0 to exit" << endl
                 << endl;

            cin >> exit;

            if(!exit) {
                return;
            }
        }
    }
}

void Flight::displaySeating()
{
    cout << "Seating Plan for Flight " << flight << endl;

    Seat seat_d;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
           

            if (!seatingPlan[r][c].getBooked())
            {
                cout << seatingPlan[r][c].getName() << "   ";
            }
            else
            {
                cout << "x    ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Flight::cancel() {
    string n, p, a;

    bool key = false;
    int index;
    Customer temp;
    
    while(!key) {
        // cout << "Seat cancellation:" << endl;
        // cout << "You will need to verify yourself with your name, phone number, and address." << endl;
        // cout << "Enter your name:";
        // cin >> n;
        // cout << "Enter your phone number:";
        // cin >> p;
        // cout << "Enter your address:";
        // cin >> a;

        p = "1";
        n = "2";
        a = "3";
            
        for(int i = 9; i >= 0; i--) {
            
            temp = passengerSeating[i];
            
            Customer empty;

            cout << temp.getName();

            if(!temp.getName().compare(n) && !temp.getAddress().compare(a) && !temp.getPhone().compare(p)) { //if name is equal to user name
                cout << endl << "Credentials Verified" << endl;

                passengerSeating[i] = empty;

                key = true;
                break;
            }
        }

        if(key) {
            break;
        }
        cout << "Your credentials are incorrect." << endl;
    }

    cout << "Hi " << temp.getName() << " for Flight " << flight << ", seat " << temp.getSeat().getName() << " was cancelled.";
    

    int ro = temp.getSeat().getRow();
    int co = temp.getSeat().getCol();
    seatingPlan[ro][co].setBooked(false);
}

void Flight::cancelFlight() {
    cout << "This flight has been canceled. These are all the customers on the flight:" << endl;
    
    for(int i = 0; i < 10; i++) {
        Customer temp = passengerSeating[i];
   
        if(temp.getName().compare("N/A")) { //if they are not equal 
            temp.displayCustomer();
            cout << endl;
        }
    
    }

}

Flight::~Flight() {}