#include "../Class_headers/Person.h"
#include "../Class_headers/Student.h"
#include "../Class_headers/Teacher.h"

int main() {
    Teacher *jim = new Teacher("jim", "tim", "k25", "asd", "C934a4");
    string teach = jim->toString();
    cout << teach;


    delete jim;
}