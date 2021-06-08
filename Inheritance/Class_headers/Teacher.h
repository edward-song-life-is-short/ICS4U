#ifndef Teacher_H
#define Teacher_H

#include "Person.h"
#include "Student.h"
#include <string>

class Teacher : public Person {
    private: 
        string teachables;
        string employeeID;
        bool isValidId(string id);
        const int ID_SIZE = 6;

    
    public:
        Teacher(string first, string last);
        Teacher(string f, string l, string a, string t, string id);
        Teacher(string f, string l, string t, string id);
        string getTeachables();
        string getEmployeeId();
        void setTeachables(string t);
        void setEmployeeId(string id);

        void markStudentLate(Student s);
        string toString();
};

#endif