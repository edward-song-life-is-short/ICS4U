#ifndef Student_H
#define Student_H

#include "Person.h"

class Student: public Person {
    private:
        bool isValidId(string);
        int grade;
        string studentID = "";
        int numLates = 0;
        int ID_SIZE = 10;
    
    public:
        Student(string first, string last);
        Student(string f, string l, string a, int g, string id);
        Student(string f, string l, int g, string id);
        int getGrade();
        string getStudentId();
        int getNumLates();
        void setGrade(int n);
        void setStudentId(string id);
        void addLate();

        string toString();
};

#endif