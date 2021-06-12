#include "../Headers/flight.h"

int main() {
    Flight *real = new Flight(123456, "Boeing 737", "New York City", "Los Angelos", "10am");
    
    //Display flight info
        real->output();
        real->displaySeating();
        real->bookSeat();
        real->displaySeating();
        real->bookSeat();
        
    
    



    // delete bo;
    // delete test;
    delete real;
}