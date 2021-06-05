#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

void q1() {
    int number;
    int* pnumber;

    number = 123;
    pnumber = &number;

    cout << "Number value:" << number << endl;
    cout << "Number address:" <<&number << endl;
    cout << "*pnumber value::" << *pnumber << endl;
    cout << "pnumber address:" << pnumber << endl;

    cout << "--------" << endl;
}

void q2() {
    int num1 = 50;
    int num2 = 100;

    int *pnum = NULL;
    pnum = &num1;
    
    *pnum = num1 + 10;

    cout << "num1:" << num1 << endl;
    cout << "pnum:" << pnum << endl;
    
    pnum = &num2;

    *pnum = num2 * 10;
    num1 = *pnum;

    cout << "num1 value:" << num1 << endl;
    cout << "pnum value:" << pnum << endl;
    cout << "*pnum value:" << *pnum << endl;

    cout << "--------" << endl;
}

void q3() {
    double value1, value2;
    value1 = 200000;

    double *lPtr;

    lPtr = &value1;

    cout << "lPtr object value:" << *lPtr << endl;

    value2 = *lPtr;
    cout << "value2 value:" << value2 << endl;
    cout << "value1 address:" << &value1 << endl;
    cout << "lPtr address:" <<  lPtr << endl;

}

int main() {
    q1();
    q2();
    q3();

}