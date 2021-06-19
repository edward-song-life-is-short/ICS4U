#ifndef FLIGHT_L_H
#define FLIGHT_L_H

#include "seat.h"
#include "customer.h"
#include "flight.h"
#include <random>

class flightList {
    private:
        //dynamic array of flights
        Flight *flightArr;

        //count flights made
        static int numFlights;
        static int totalProfit;
    
    public:
        flightList();
        flightList(int n_arr); //generate n number of flights

        void cancelFlight(int flight_id);

        void selectFlight();
        
        void cancelSeat(int flight_id);
        void bookFlight(int flight_id);
        void displayFlight(int flight_id);
        void testings(int ns);

        int returnCash();


        void deAllocate();

        ~flightList();



};




#endif