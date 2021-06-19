#include "../Headers/flight.h"
#include "../Headers/customer.h"
//basic flight from New York to LA that happens 9am every day

int Flight::flightProfit = 0;
bool Flight::testVar = false;

Flight::Flight()
{
    origin = "N/A";
    destination = "N/A";
    plane = "N/A";
    time = "N/A";
    flight = 0;

    initializeSeats();
}

//declare empty seats, determine business and economy seats 
void Flight::initializeSeats()
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {

            //dynamic objects
            Seat *temp = new Seat(c, r);

            //first 2 rows of seats are business class
            if (r < 2)
            {
                temp->setBusiness(true);
            }
            else
            {
                temp->setBusiness(false);
            }

            seatingPlan[r][c] = *temp;

            //clear some memory 
            delete temp;
        }
    }
}

//deep copy, operator overloading 
Flight &Flight::operator=(const Flight &copy)
{
    origin = copy.origin;
    destination = copy.destination;
    plane = copy.plane;
    time = copy.time;
    flight = copy.flight;

    return *this;
}

//manual flight constructor -> input specific info
Flight::Flight(int num, string plane, string o, string d, string t)
{
    this->setFlightName(num);
    this->setPlane(plane);
    this->setLocation(o, d);
    this->setTime(t);

	//iniatialize 
    initializeSeats();
    intializePassArr();
}

int Flight::flightNum = 0;

Flight::Flight(int p, int o, int d, int t)
{
    //random generation of flights, using values from constant static arrays
    flight = 100000 + flightNum;
    plane = registeredPlanes[p];
    origin = places[o];
    destination = places[d];
    time = to_string(t) + "pm";

    flightNum++;

	initializeSeats();
	intializePassArr();
}

void Flight::intializePassArr()
{
    //create an empty set of passengers in the array
    for (int i = 0; i < 10; i++)
    {
        Customer *empty = new Customer();
        passenger[i] = *empty;
    }
}

void Flight::setFlightName(int id)
{
    stringstream id_str;
    id_str << id;
    //input checks
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
    //input checks
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
    //input checks for destination and origin
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
        if (!places[i].compare(o)) //if they are equal
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
    time = t;
}

//output flight info
void Flight::output()
{
    cout << "Flight Summary" << endl
         << endl;

    cout << "Flight Number:" << flight << endl;

    if (origin.compare("Invalid") && destination.compare("Invalid"))
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
    //convert char to readable int
    int seatNum = s[0] - '0';

    char letter = s[1];

    //input checks for seats
    if (s.length() != 2 || (seatNum < 1 || seatNum > 5) || (letter != 'a' && letter != 'b' && letter != 'A' && letter != 'B'))
    {
        valid = false;
    }

    return valid;
}

void Flight::logCustomer(Seat &s)
{
    //array storing customer info
    string info[4];
    string l;

    if (!testVar)
    {
        cout << "Congratulations on booking your seat. We need to log some of your personal information:" << endl;
        cout << "Enter your name:" << endl;
        cin >> info[0];
        cout << "Enter your phone number:" << endl;
        cin >> info[1];
        cout << "Enter your address:" << endl;
        cin >> info[2];
        cout << "Enter credit card info:" << endl;
        cin >> info[3];

        cout << "This ticket has been purchased for " << s.returnPrice() << ". Customer Information:" << endl;
    }
    else //constant values when testing 
    {
        info[0] = "1";
        info[1] = "2";
        info[2] = "3";
        info[3] = "4";
    }

    //declare a customer using given information
    Customer temp(info[0], info[1], info[2], info[3], s);

    //place customers into the array based on available seats
	passengerSeating[10 - available - 1] = temp;

    //add profit generated from the seat
    flightProfit += s.returnPrice();

    //printed when not testing 
    if (!testVar)
        temp.displayCustomer();

}

//book seat function
void Flight::bookSeat()
{
    bool valid;
    string newSeat;
    int exit = 1;

    valid = false;

    if (testVar)
    {
        //iterate through 2d seat array
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
				seatingPlan[r][c].setBooked(true); //book every single seat
		
                //decrease available seats
				available--;
                //pass seat to customer info function
				logCustomer(seatingPlan[r][c]);
				
            }
        }
        
		cout << "All seats on Flight " << flight << " booked." << endl;

        return;
    }

    //making sure input is correct 
    while (!valid)
    {
        this->displaySeating();

        cout << "Enter the seat you want to book:" << endl;

        cin >> newSeat;

        valid = readSeat(newSeat);

        if (valid)
        {
            break;
        }

        cout << "Invalid Seat Number, Enter a valid seat:" << endl;
    }

    //convert to normal 
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

    //if the seat is not booked 
    if (!seatingPlan[local_r][local_c].getBooked())
    {
        cout << "Your seat " << newSeat << " has been booked successfully." << endl
             << endl;

        seatingPlan[local_r][local_c].setBooked(true);
        valid = false;

        available--;

        //find price of seat 
        int pricing = seatingPlan[local_r][local_c].returnPrice();

        if (seatingPlan[local_r][local_c].returnBusiness())
        {
            cout << "This is a business class seat that costs " << pricing << endl;
        }
        else
        {
            cout << "This is an economy class seat that costs " << pricing << "$" << endl;
        }

        //show perks of the seat 
        seatingPlan[local_r][local_c].displayPerks();

        //log seat info 
        logCustomer(seatingPlan[local_r][local_c]);
    }
    else //seat is already booked 
    {
        cout << "This seat is not available." << endl;

        if (available > 0)
        {
            cout << "Here are the seats that are available:" << endl
                 << endl;

            this->displaySeating();

            cout << "Book another seat:" << endl;
            bookSeat();
        }
        else
        {
            cout << "There are not any other avaiable seats for this flight. Enter 0 to exit" << endl
                 << endl;

            cin >> exit;

            if (!exit)
            {
                return;
            }
        }
    }
}

//display seats 
void Flight::displaySeating()
{
    cout << "Seating Plan for Flight " << flight << endl;

    Seat seat_d;

    //iterate through the seat array 
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            //determine what to print when seats are booked or not 
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

//mutator 
void Flight::setTestVar(bool b)
{
    testVar = b;
}

void Flight::cancel()
{
    string n, p, a, s;

    int exit = -1;

    bool key = false;
    int index;
    Customer temp;

    if (available == 10)
    {
        cout << "No seats have been booked." << endl;
        return;
    }

    if (testVar)
    {
		for(int r = 0; r < rows; r++) {
			for(int c = 0; c < cols; c++) {
				seatingPlan[r][c].setBooked(false); //unbook seat
				available++; //increase seats available
				flightProfit -=seatingPlan[r][c].returnPrice(); //decrease total profits from flight
			}
		}
			
        cout << "All seats on Flight " << flight << " canceled " << endl;
        
        return;
    }

    while (!key)
    {
        if (!testVar)
        {
            cout << "Seat cancellation:" << endl;
            cout << "You will need to verify yourself with your name, phone number, and credit card. Enter 0 to exit and 1 to continue." << endl;

            //more checks for proper input 
            while (exit != 0 && exit != 1)
            {
                cin >> exit;
            }

            if (exit == 0)
            {
                return;
            }

            //take some info
            cout << "Enter your name:";
            cin >> n;
            cout << "Enter your phone number:";
            cin >> p;
            cout << "Enter your credit card:";
            cin >> a;
            cout << "Enter your seat with correct capitalization (1A)" << endl;
            cin >> s;
        }

        for (int i = 0; i < 10; i++)
        {

            //create temp customer to store info
            temp = passengerSeating[i];

            Customer empty;

            cout << temp.getCredit();

            //checking all info is correct 
            if (!temp.getName().compare(n) && !temp.getSeat().getName().compare(s) && !temp.getPhone().compare(p) && !testVar)
            { //if name is equal to user name
                cout << endl
                     << "Credentials Verified. Your ticket will be refunded." << endl;

                passengerSeating[i] = empty;


                key = true;
                break;
            }
        }

        if (key)
        {
            break;
        }
        cout << "Your credentials are incorrect." << endl;
    }

    cout << "Hi " << temp.getName() << " for Flight " << flight << ", seat " << temp.getSeat().getName() << " was cancelled.";

    //decrease prices
    flightProfit -= temp.getSeat().returnPrice();

    //find rows and columns of the seats 
    int ro = temp.getSeat().getRow();
    int co = temp.getSeat().getCol();
    seatingPlan[ro][co].setBooked(false);
	available++;
}

//use modified selection sort to sort the array of passenger by seats
void Flight::sortArray()
{
    cout << "Passengers have been sorted by their seats:" << endl;

    int min;
    int n = 10 - available; //only sort customer seats that have been booked since the rest of the elements have not been intialized with customer information just "n/a" in the default constructor

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            //store info temporarily 
            Customer tempCus = passengerSeating[j];
            cout << "tets";
            
            //indexes of passenger seat
            int ind1 = tempCus.getSeat().getName()[0] - '0';
            char ind2 = tempCus.getSeat().getName()[1];
            int comp1 = passengerSeating[min].getSeat().getName()[0] - '0';
            char comp2 = passengerSeating[min].getSeat().getName()[1];

            cout << "i1 " << ind1 << " i2 " << ind2 << " c1 " << comp1 << " c2 " << comp2;

            if (ind1 <= comp1 && ind2 <= comp2)
                min = j;

            // Swap the found minimum element with the first element
            Customer temp = passengerSeating[min];
            passengerSeating[min] = passengerSeating[i];
            passengerSeating[i] = temp;
        }
    }
}

void Flight::cancelFlight()
{
    cout << "This flight has been canceled. These are all the customers on the flight:" << endl;

    sortArray();

    for (int i = 0; i < 10; i++)
    {
        Customer temp = passengerSeating[i];

        if (temp.getName().compare("N/A"))
        { //if they are not equal
            temp.displayCustomer();
            cout << endl;
        }
    }
}

//accessor fucntions
string Flight::returnLocation()
{
    return origin + " to " + destination;
}

string Flight::returnTime()
{
    return time;
}

int Flight::returnFlight()
{
    return flight;
}

int Flight::returnFlightCash()
{
    return flightProfit;
}

Flight::~Flight() {}