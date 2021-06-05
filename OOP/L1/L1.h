#ifndef L1_H
#define L1_H

#include <string>

using namespace std;

class Student {
    public:
        Student();

        void setAge(int a);
        void setGrade(int g);

        void printInfo();
    
    private:
        int age;
        int grade;

    
    

};

#endif 
