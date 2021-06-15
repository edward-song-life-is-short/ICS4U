#include "../Headers/flight.h"
#include "../Headers/flightList.h"

int main() {
    srand((unsigned) time(0));
    
    flightList *test = new flightList();
    test->selectFlight();


    // delete bo;
    // delete test;
    delete test;
}