#include "Person.h"

Person::Person() {
    firstName = "N/A";
    lastName = "N/A";
    address = "N/A";
}

Person::Person(string fName, string lName) {
    firstName = fName;
    lastName = lName;
    address = "N/A";
}

Person::Person(string fName, string lName, string add) {
    firstName = fName;
    lastName = lName;
    address = add;
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

string Person::getAddress() {
    return address;
}

void Person::setFirstName(string fName) {
    firstName = fName;
}

void Person::setLastName(string lName) {
    lastName = lName;
}

void Person::setAddress(string add) {
    address = add;
}

string Person::toString() {
    cout << "First Name:" << firstName << endl;
    cout << "Last Name:" << lastName << endl;
    cout << "Address:" << address << endl;
}

