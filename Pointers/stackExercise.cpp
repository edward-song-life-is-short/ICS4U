
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

void q1a() {
    int length;
    int *ArrayPtr;
    cout << " Please enter the length of the array " << endl;
    cin >> length;
    ArrayPtr = new int[length];
    cout << "Please enter the elements of the array " << endl;
    for (int index = 0; index <= length -1; index++)
        cin >> ArrayPtr[index];
    for (int index = 0; index <= length -1; index++)
        cout << ArrayPtr[index]<<endl;
    
    delete[] ArrayPtr; //deallocate memory for array
    
}

void q1b() {
    int length;
    int *ArrayPtr;
    cout << " Please enter the length of the array " << endl;
    cin >> length;
    ArrayPtr = new int[length];
    cout << "Please enter the elements of the array " << endl;
    for (int index = 0; index <= length -1; index++)
        cin >> ArrayPtr[index];

    for(int i = length-1; i >= 0; i--) {
        cout << ArrayPtr[i] << endl;
    }

    delete[] ArrayPtr;
}

void q1c() {
    int length;
    int *ArrayPtr;
    
    cout << " Please enter the length of the array " << endl;
    cin >> length;
    ArrayPtr = new int[length];
  
    int sum = 0;

    for (int index = 0; index <= length -1; index++) {
        ArrayPtr[index] = rand() % 50 + 1;
        sum += ArrayPtr[index];
    }

    cout << "Sum of elements:" << sum << endl;
    delete[] ArrayPtr;
}

void q1d() {
    
    srand(0);

    int length, length2;
    int *ArrayPtr;
    int *Array2Ptr;
    int *Array3Ptr;

    int totalLength=0;

    cout << " Please enter the length of the first array " << endl;
    cin >> length;
    ArrayPtr = new int[length];
    
    for (int index = 0; index <= length -1; index++) {
        ArrayPtr[index] = rand() % 50 + 1;
    }

    cout << " Please enter the length of the second array " << endl;
    cin >> length2;
    Array2Ptr = new int[length2];

    totalLength = length2 + length;
	
	for(int i = 0; i < length2; i++) {
        Array2Ptr[i] = rand() % 50 + 1;
    }

    
    Array3Ptr = new int[totalLength];

    for(int i = 0; i < totalLength; i++) {
        if(i <= length-1) {
            Array3Ptr[i] = ArrayPtr[i];
        }
        else {
            Array3Ptr[i] = Array2Ptr[i - length];
        }
    }

	cout << "Total array elements:" << endl;

    for(int i = 0; i < totalLength; i++) {
        cout << Array3Ptr[i] << endl;
    }

    delete[] Array3Ptr;
    delete[] Array2Ptr;
    delete[] ArrayPtr;
}

int main() {
    q1a();
    q1b();
    q1c();
    q1d();
}