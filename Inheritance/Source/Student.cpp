#include "../Class_headers/Student.h"

using namespace std;
#include <sstream>

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
void Student::setGrade(int n) {
    grade = n;
}

void Student::setStudentId(string id) {
    studentID = id;
}

void Student::addLate() {
    numLates++;
}

bool Student::isValidId(string id) {
    if(id.length() != 10 || id.at(0) == 'C') { 
        return false;
    }

}

string Student::toString() {
    string s_str = this->generalString();
    
    stringstream stud_s;
    stud_s << "ID:" << studentID << endl;
    stud_s << "Grade:" << grade << endl;
    stud_s << "Late times:" << numLates << endl;
    
    return s_str += stud_s.str();
}