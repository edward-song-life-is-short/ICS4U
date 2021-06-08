#include "Student.h"

Student::Student(string first, string last) : Person(first, last) {
    grade = 0;
    studentID = "";
}

Student::Student(string f, string l, string a, int g, string id) : Person(f, l, a) {
    grade = g;
    studentID = id;
}

Student::Student(string f, string l, int g, string id) : Person(f, l) {
    grade = g;
    studentID = id;
}

int Student::getGrade(){
    return grade;
}

string Student::getStudentId() {
    return studentID;
}

int Student::getNumLates() {
    return numLates;
}
void setGrade(int n);
void setStudentId(string id);
void addLate();
