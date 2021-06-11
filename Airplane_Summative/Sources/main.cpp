#include "../Headers/flight.h"

int main() {
    Flight *real = new Flight(123456, "Boeing 737", "New York City", "Los Angelos", "10am");
    
    //Display flight info
        real->output();

        real->bookSeat("1a");
        real->bookSeat("1a");
    
    



    // delete bo;
    // delete test;
    delete real;
}