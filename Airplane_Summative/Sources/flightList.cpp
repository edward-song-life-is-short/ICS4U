#include "../Headers/flightList.h"

//initialize static variables 
int flightList::numFlights = 0;
int flightList::totalProfit = 0;

//default constructor -> 10 flights, with random values, origin, destination, etc
flightList::flightList()
{

    numFlights = 10;

    flightArr = new Flight[10];

    int r_p, r_o, r_d, r_ti; //random numbers generated

    for (int i = 0; i < 10; i++)
    {
        r_p = rand() % 3;
        r_o = rand() % 4;
        r_d = (rand() % 5) + 4;
        r_ti = (rand() % 12) + 1;

        Flight *temp = new Flight(r_p, r_o, r_d, r_ti);
        flightArr[i] = *temp;
        delete temp;

    }
}

//constructor used for testing -> generate n number of flights 
flightList::flightList(int n)
{   
    numFlights = n;

    flightArr = new Flight[n];

    int r_p, r_o, r_d, r_ti; //random numbers generated

    for (int i = 0; i < n; i++)
    {
        //random values
        r_p = rand() % 3;
        r_o = rand() % 4;
        r_d = (rand() % 5) + 4;
        r_ti = (rand() % 12) + 1;

        //dynamic object 
        Flight *temp = new Flight(r_p, r_o, r_d, r_ti);
        flightArr[i] = *temp;
        delete temp;
    }

    cout << n << " Flight(s) have been generated" << endl;
}

//deallocate dynamic memory 
void flightList::deAllocate() {
    delete [] flightArr;
}

void flightList::testings(int ns) {
   for(int i = 0; i < ns; i++) {
		//set testing mode on
		flightArr[i].setTestVar(true);
		
        //testing stability and functionality 
        
        //book every seat on the flight
        bookFlight(i);
		cancelSeat(i); //cancel every seat
		displayFlight(i); //display flight status
		bookFlight(i); //book every seat
		//find revenue generated
		cout << "Total Revenue:" << totalProfit << endl;
	}

}

//flight selection
void flightList::selectFlight()
{
    int select = 0;
    int modeSelect = -1;
    bool testing = false;
    int input = 0;
    

    while (modeSelect < 0 || modeSelect > 3)
    {

        cout << "Here are the list of flights you can select from" << endl;

        //output flight info
        for (int i = 0; i < numFlights; i++)
        {
            if(flightArr[i].returnFlight() == 0)
                continue;
            
            cout << i + 1 << "." << "Flight " << flightArr[i].returnFlight() << " from " << flightArr[i].returnLocation() << " at " << flightArr[i].returnTime() << endl;
        }   

        //input check
        while (select <= 0 || select > 10)
        {
            cout << "Select a flight using values 1 -> 10" << endl;
            cin >> select;
        }
 
        cout << "Select the options you want with the corresponding numbers (e.g 1):" << endl;
        cout << "0. Exit program" << endl;
        cout << "1. Cancel a flight" << endl;
        cout << "2. Cancel a seat" << endl;
        cout << "3. Book a seat." << endl;
        cout << "4. Display flight seating" << endl;
        cout << "5. Show profits" << endl;

        cin >> modeSelect;

        
        //call diff functiosn corresponding to flight info
        if (modeSelect == 1)
        {
            cancelFlight(select - 1);
        }
        else if (modeSelect == 2)
        {
            cancelSeat(select - 1);
        }
        else if (modeSelect == 0)
        {
            return;
        }
        else if(modeSelect == 4) {
            displayFlight(select-1);
        }
        else if(modeSelect == 5) {
            cout << totalProfit << "$ gathered." << endl;
        }
        else
        {
            bookFlight(select - 1);
        }

        modeSelect = -1;
        select = 0;
    }
}

void flightList::cancelSeat(int id) {
    int origin = flightArr[id].returnFlightCash();
    
    flightArr[id].cancel();
    
    //find new revenue
    totalProfit -= (origin - flightArr[id].returnFlightCash());
}

void flightList::displayFlight(int id) {
    flightArr[id].displaySeating();
}

void flightList::bookFlight(int id)
{
    if(flightArr[id].returnFlight() == 0) {
        cout << "This flight has been cancelled." << endl;
        return;
    }
    
    int origin = flightArr[id].returnFlightCash();

    flightArr[id].bookSeat();
    totalProfit += (flightArr[id].returnFlightCash() - origin); 
    
    
    flightArr[id].displaySeating();
}

//deletion of flights
void flightList::cancelFlight(int id)
{
   
    flightArr[id].cancelFlight();

    totalProfit -= flightArr[id].returnFlightCash();


    Flight *empty = new Flight();

    flightArr[id] = *empty;

    delete empty;
}

int flightList::returnCash() {
    return totalProfit;
}

flightList::~flightList() {}