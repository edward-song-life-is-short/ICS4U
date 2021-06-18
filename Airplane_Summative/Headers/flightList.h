#ifndef FLIGHT_L_H
#define FLIGHT_L_H

#include "seat.h"
#include "customer.h"
#include "flight.h"
#include <random>

class flightList {
    private:
        Flight *flightArr;
        static int numFlights;
        static int totalProfit;
    
    public:
        flightList();
        flightList(int n_arr);

        void cancelFlight(int flight_id);

        void selectFlight();
        
        void cancelSeat(int flight_id);
        void bookFlight(int flight_id);
        void displayFlight(int flight_id);
        

        int returnCash();


        void deAllocate();



};




#endif