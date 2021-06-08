#include "Person.h"

class Student: public Person {
    private:
        bool isValidId(string);
        int grade;
        string studentID;
        int numLates;
    
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
};