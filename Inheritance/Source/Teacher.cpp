#include "../Class_headers/Teacher.h"
#include <sstream>

bool Teacher::isValidId(string id) {
    if(id.length() != 6 || id[0] != 'C') {
        return false;
    }

    char f_char;
    for(int i = 1; i < ID_SIZE; i++) {
        f_char = id[i];
        
        if(!isdigit(f_char)) {
            return false;
        }
    }

    return true;
}

Teacher::Teacher(string first, string last) : Person(first, last) {
    teachables = "N/A";
    employeeID = "N/A";
}


Teacher::Teacher(string f, string l, string a, string t, string id) : Person(f, l, a) {
    teachables = t;
    this->setEmployeeId(id);
}

Teacher::Teacher(string f, string l, string t, string id) : Person(f, l){
    teachables = t;
    this->setEmployeeId(id);
}

string Teacher::getTeachables() {
    return teachables;
}
string Teacher::getEmployeeId() {
    return employeeID;
}

string Teacher::toString() {
    string t_str = this->generalString();
    stringstream t_ss;
    t_ss << "ID:" << employeeID << endl;
    t_ss << "Subject:" << teachables << endl;
    
    return t_str += t_ss.str();

}

void Teacher::markStudentLate(Student& s) {
    s.addLate();
}

void Teacher::setTeachables(string t) {
    teachables = t;
}
void Teacher::setEmployeeId(string id) {
    bool valid = this->isValidId(id);

    if(!valid) {
        employeeID = "Invalid ID";
    } else {
        employeeID = id;
    }

}
