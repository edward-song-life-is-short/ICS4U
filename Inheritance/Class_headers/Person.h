#ifndef Person_H
#define Person_H

#include <string>
#include <iostream>

using namespace std;

class Person {
    private:
        string firstName;
        string lastName;
        string address;

    public:
        Person();
        Person(string, string);
        Person(string, string, string);
        
        string getFirstName();
        string getLastName();
        string getAddress();

        void setFirstName(string);
        void setLastName(string);
        void setAddress(string);

        string generalString();
   
};

#endif