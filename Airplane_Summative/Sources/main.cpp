#include "../Headers/flight.h"
#include "../Headers/flightList.h"

int main() {
    srand((unsigned) time(0));
    
	cout << "Select a mode:" << endl;
    cout << "1. Testing Functionality" << endl;
    cout << "2. Flight Operations" << endl;

	int input = -1;

    while(input <= 0 || input > 2) {
        cin >> input;
    }

    if(input == 2) {
        flightList *test = new flightList();
    	test->selectFlight();
		delete test;
    } 
	if(input == 1) {
		 int n;
    
		cout << "Input how many flights you want to generate:" << endl;
		cin >> n;

		flightList *test = new flightList(n);
		
		test->testings(n);
		delete test;
	}
	 

}