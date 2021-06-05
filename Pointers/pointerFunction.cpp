//Edward Song, January 6 2021

#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <cmath>

#define _USE_MATH_DEFINES

//question 1
void cubeByPointer(float * number) {
   *number = pow(*number, 3);
}

//question 2
void sumTwoInt(int * one, int * two) {
    *one = *one + *two;
}

//question 3
void circle(double * r, double * area, double * circumference) {
    *area = M_PI * pow(*r, 2);
    *circumference = 2*M_PI*(*r);
}

//question 4
bool quadEquation(double a, double b, double c, double * root1, double * root2) {
    bool root = true;
    
    if(pow(b, 2) - 4*a*c < 0) {
        root = false;
    }
    else {
        *root1 = (-b + sqrt(pow(b, 2) - 4*a*c))/2*a;
        *root2 = (-b - sqrt(pow(b, 2) - 4*a*c))/2*a;
    }

    return root;

}

//question 5
// void swap(float *p1, float *p2){
//     float *temp;
//     temp = p1;
//     p1 = p2;
//     p2 = temp;
// }

//the swap does not work, the function swaps memory addresses
//a pointer points to the memory address
//you need to dereference a pointer using the * operator to access the pointer value

void swap(float *p1, float *p2){
    float temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//question 6
void SquareComplex(double *a, double *b) {
    // Squares a complex number a + bi
    *a = *a * (*a) - *b * (*b);
    *b = 2*(*a)*(*b);
    //I modified the code to add more "*" operators to access the value of the pointers
    //brackets were added to clarify the difference between "*" which is used to dereference 
    //the arguments in the function were changed to *a instead of &a to access the pointer values
    //&a is incorrect because it takes in the memory addresses of the variables
}

int main() {
    float number = 9;
    cubeByPointer(&number);
    cout << "number value:" << number << endl;

    cout << "-----------" << endl;

    int one = 1, two = 2;
    sumTwoInt(&one, &two);
    cout << "sum:" << one << endl;

    cout << "-----------" << endl;

    double radius = 3, area = 5, circumference = 9;
    circle(&radius, &area, &circumference);
    cout << "Area:" << area << endl;
    cout << "Circumference:" << circumference << endl;

    cout << "-----------" << endl;

    double a = 1, b = -2, c = -3;
    double root1 = 0, root2 = 0;

    bool root = quadEquation(a, b, c, &root1, &root2);

    if(root) {
        cout << "root one:" << root1 << endl;
        cout << "root two:" << root2 << endl;
    }
    else {
        cout << "No roots" << endl;
    }

    cout << "-----------" << endl;

    float n1 = 5, n2 = 6;

    swap(&n1, &n2);

    cout << "n1:" << n1 << endl;
    cout << "n2:" << n2 << endl;

    cout << "-----------" << endl; 

    double a1 = 3, b2= 2;
    SquareComplex(&a1, &b2);
    cout << "a value:" << a1 << endl;
    cout << "b value:" << b2 << endl;



}