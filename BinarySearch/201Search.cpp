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

int elements[20000];
int randArray[20000];

void createRndArray(int high, int low, int n) {
    srand(0);

    for(int i = 0; i < n; i++) {
        randArray[i] = rand()%high + low;
    }
    int max = randArray[0];

    for(int sort = 0; sort < n; sort++) {
        
        int max = sort;
        for(int i = 1; i < n; i++) {
            if(randArray[i] > randArray[sort]) {
                max = i;
            }
        }

        int temp = randArray[sort];
        randArray[sort] = randArray[max];
        randArray[max] = temp;
    }

    for(int i = 0; i < n; i++) {
        cout << randArray[i] << " ";
    }
}

void printArray(int arr[], int start, int end) {
    for(int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    if(start != end) {
        cout << endl;
    }
}

int linearSearch(int arr[], int value, int n) { 
    for(int i = 0; i < n; i++) {
        printArray(arr, i, n);

        if(arr[i] == value) {
            cout << "found at index " << i << endl;
            return 1;
        }
    }


    cout << "not found" << endl;
    return -1;
}

int binarySearchLoop(int arr[], int value, int n) {
    int start = 0, end = n-1;
    int found = false;
    int middle = 0;
    
    middle = (start + end + 1)/2;        
    while(start <= end && !found) {
        middle = (start + end + 1)/2;    

       // cout << "s:" << start << " e:" << end << endl;

        printArray(arr, start, end+1);

        if(value > arr[middle]) {
            start = middle + 1;
               
        }
        else if(value < arr[middle]) {
            end = middle - 1;
        }
        else {
            if(start != end) {
                printArray(arr, middle, middle+1);
            }
            found = true;
            
        }

    }

    if(found) {
        cout << "found at index " << middle;
        return 1;
    }
    else {
        cout << "not found";
        return -1;
    }
} 

int binarySearchRecursion(int arr[], int value, int start, int end) {
    
    if(end>=1) {
        int mid = start + (end - 1)/2;

        if(arr[mid] == value) {
            return mid;
        }

        if(arr[mid] > value) {
            return binarySearchRecursion(arr, value, start, mid-1);
        }

        return binarySearchRecursion(arr, value, mid+1, end);
    }

    return -1;
}



int main() {
    int n, x, element;

    cin >> n;
    cin >> x;

    for(int i = 0; i < n; i++) {
        cin >> element;
        elements[i] = element;
    }   

    sort(elements, elements + n);

    cout << "Linear Search" << endl;
    int linearFound = linearSearch(elements, x, n);
   
    cout << endl << "Binary Search" << endl;
    int binaryFound = binarySearchLoop(elements, x, n);
    
}