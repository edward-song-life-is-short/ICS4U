#include "../Class_headers/Person.h"
#include "../Class_headers/Student.h"
#include "../Class_headers/Teacher.h"

int main() {
    //testing valid ids -> this is incorrect
    Student *tim = new Student("tim", "jim", "k4t", 5, "S12345678a");
    cout << tim->toString();

    //invalid
    tim->setStudentId("C123456789");
    cout << endl << tim->toString();

    //invalid
    tim->setStudentId("S12345678910");
    cout << endl << tim->toString();

    //valid
    tim->setStudentId("S123456789");
    cout << endl << tim->toString();


    //invalid
    Teacher *jim = new Teacher("jim", "tim", "k25", "asd", "C934a4");
    cout << jim->toString();

    //valid
    jim->setEmployeeId("C93453");
    cout << endl << jim->toString();

    //invalid
    jim->setEmployeeId("S94564");
    cout << endl << jim->toString();

    //mark student as late
    for(int i = 0; i < 10; i++) {
        jim->markStudentLate(*tim);
    }

    tim->addLate();
    cout << endl << tim->toString();

    


    delete jim;
    delete tim;
}