#include "../Headers/flight.h"

int main() {
    // Flight *bo = new Flight();
    // bo->output();


    // Flight *test = new Flight(1234555, "bo", "New Yowrk", "Los Afsaf", "9am");
    // test->output();

    Flight *real = new Flight(123456, "Boeing 737", "New York City", "Los Angelos", "10am");
    real->output();
    
    // delete bo;
    // delete test;
    delete real;
}