#include "../Headers/flightList.h"

int flightList::numFlights = 0;
int flightList::totalProfit = 0;

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

    }
}

flightList::flightList(int n)
{   
    numFlights = n;

    flightArr = new Flight[n];

    int r_p, r_o, r_d, r_ti; //random numbers generated

    for (int i = 0; i < n; i++)
    {
        r_p = rand() % 3;
        r_o = rand() % 4;
        r_d = (rand() % 5) + 4;
        r_ti = (rand() % 12) + 1;

        Flight *temp = new Flight(r_p, r_o, r_d, r_ti);
        flightArr[i] = *temp;

    }

    cout << n << " Flight(s) have been generated" << endl;
}

void flightList::deAllocate() {
    delete [] flightArr;
}

void flightList::testings(int ns) {
   for(int i = 0; i < ns; i++) {
			
		flightArr[i].setTestVar(true);
		bookFlight(i);
		cancelSeat(i);
		displayFlight(i);
		bookFlight(i);
		
		cout << "Total profit:" << totalProfit << endl;
	}

}

void flightList::selectFlight()
{
    int select = 0;
    int modeSelect = -1;
    bool testing = false;
    int input = 0;
    

    while (modeSelect < 0 || modeSelect > 3)
    {

        cout << "Here are the list of flights you can select from" << endl;

        for (int i = 0; i < numFlights; i++)
        {
            if(flightArr[i].returnFlight() == 0)
                continue;
            
            cout << i + 1 << "." << "Flight " << flightArr[i].returnFlight() << " from " << flightArr[i].returnLocation() << " at " << flightArr[i].returnTime() << endl;
        }

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