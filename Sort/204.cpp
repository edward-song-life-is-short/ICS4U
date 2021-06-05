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

void q1()
{
    cout << "Q1" << endl;
    cout << "(3  8) 3  2  7  5" << endl;
    cout << " 3 (8  3) 2  7  5" << endl;
    cout << " 3  3 (8  2) 7  5" << endl;
    cout << " 3  3  2 (8  7) 5" << endl;
    cout << " 3  3  2  7 (8  5)" << endl;
    cout << "(3  3) 2  7  5  8" << endl;
    cout << " 3 (3  2) 7  5  8" << endl;
    cout << " 3  2 (3  7) 5  8" << endl;
    cout << " 3  2  3 (7  5) 8" << endl;
    cout << "(3  2) 3  5  7  8" << endl;
    cout << " 2 (3  3) 5  7  8" << endl;
    cout << " 2  3 (3  5) 7  8" << endl;
    cout << "(2  3) 3  5  7  8" << endl;
     cout << "2 (3  3)  5  7  8" << endl;
    cout << " 2  3  3  5  7  8" << endl;
}

void bubbleSort(int arr[], int length)
{
    bool sorted = false;
    for (int i = length - 1; i > 0 && !sorted; i--)
    {
        sorted = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void q3() {
    cout << "(2  9) 4  6  1  7  4" << endl;
    cout << " 2 (9  4) 6  1  7  4" << endl;
    cout << " 2  4 (9  6) 1  7  4" << endl;
    cout << " 2  4  6 (9  1) 7  4" << endl;
    cout << " 2  4  6  1 (9  7) 4" << endl;
    cout << " 2  4  6  1  7 (9  4)" << endl;
    cout << " 2  4  6  1 (7  4) 9" << endl;
    cout << " 2  4  6 (1  4) 7  9" << endl;
    cout << " 2  4 (6  1) 4  7  9" << endl;
    cout << " 2 (4  1) 6  4  7  9" << endl;
    cout << "(2  1) 4  6  4  7  9" << endl;
    cout << " 1  2  4  6  4  7  9" << endl;
}

int shakerSort(double arr[], double n) {
    bool sorted = false;
    int begin = 0;
    int end = n -1;
    double temp;
    int counter = 0;
    while(!sorted) {
        sorted = true;

        for(int i = begin; i < end; i++) {
            if(arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i+1] = temp;
                sorted = false;
                counter++;
            }
        }

        if(sorted) {
            break;
        }

        sorted = true;

        end--;

        for(int i = end -1; i >=begin; i--) {
            if(arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i+1] = temp;
                sorted = false;
                counter++;
            }
        }

        begin++;
    }

    return counter;
}

double elmts[200000];

int main()
{
    int n;
    double elements;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> elements;
        elmts[i] = elements;
    }
    
    //Question 1
    q1();

    //Question 2
    //change the greater sign to a less than equal sign when comparing 
    //arr[j] and arr[j+1];

    //Question 3
    cout << "Q3" << endl;
    q3();
    
    //Question 4
    cout << "Q4" << endl;
    int counter = shakerSort(elmts, n);

    for(int i = 0; i < n; i++) {
        cout << elmts[i] << " ";
    }
    cout << endl;
    cout << counter << endl;
}
