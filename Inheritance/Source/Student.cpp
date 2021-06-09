#include "../Class_headers/Student.h"

using namespace std;
#include <sstream>

bool Student::isValidId(string id) {
    if(id.length() != ID_SIZE || id[0] != 'S') {
        return false;
    }

    for(int i = 1; i < ID_SIZE; i++) {
        if(!isdigit(id[i])) {
            return false;
        }
    }

    return true;
}

Student::Student(string first, string last) : Person(first, last) {
    grade = 0;
    studentID = "";
}

Student::Student(string f, string l, string a, int g, string id) : Person(f, l, a) {
    grade = g;
    this->setStudentId(id);
}

Student::Student(string f, string l, int g, string id) : Person(f, l) {
    grade = g;
    this->setStudentId(id);
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
    bool valid = this->isValidId(id);

    if(!valid) {
        studentID = "Invalid ID";
    }
    else {
        studentID = id;
    }
}

void Student::addLate() {
    numLates++;
}

string Student::toString() {
    string s_str = this->generalString();
    
    stringstream stud_s;
    stud_s << "ID:" << studentID << endl;
    stud_s << "Grade:" << grade << endl;
    stud_s << "Late times:" << numLates << endl;
    
    return s_str += stud_s.str();
}