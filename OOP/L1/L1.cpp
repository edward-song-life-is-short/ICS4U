#include <iostream>
#include "L1.h"

using namespace std;


Student::Student() {
    age = 1;
    grade = 0;
}



void Student::setAge(int a) {
    age = a;
}

void Student::setGrade(int g) {
    grade = g;
}

void Student::printInfo() {
    cout << "age:" <<  age << endl;
    cout << "grade:" << grade << endl;
}


int main() {
    Student jim;
    
    jim.printInfo();
    jim.setGrade(5);
    jim.setAge(10);
    jim.printInfo();
    

}