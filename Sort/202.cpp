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

double elements[20000];

void insertionPlanet(string arr[], int size) {
    int current;
    string temp;
 
    for(int i = 1; i < size; i++) {

        current = i;

        while(current > 0 && arr[current] < arr[current-1]) {
            temp = arr[current];
            arr[current] = arr[current -1];
            arr[current-1] = temp;
            current--; 
        }
        for(int t = 0; t < 8; t++) {
            cout << arr[t] << " ";
        }
        cout << endl;
    }
}

void insertion(double arr[], int size) {
    int current;
    double temp;
 
    for(int i = 1; i < size; i++) {

        current = i;

        while(current > 0 && arr[current] < arr[current-1]) {
            temp = arr[current];
            arr[current] = arr[current -1];
            arr[current-1] = temp;
            current--; 
        }
    }
}

void planetSort() {
    string planets[8] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};

    for(int i = 0; i < 8; i++) {
        cout << planets[i] << " ";
    }
    cout << endl;

    insertionPlanet(planets, 8);

}

int main() {
    int size; 
    double element;

    cin >> size;
    
    for(int i = 0; i < size; i++) {
        cin >> element;
        elements[i] = element;
    }

    
    //Question 1
    cout << "Q1" << endl;
    cout << "6 2 8 3 1 7 4" << endl;
    cout << "2 6 8 3 1 7 4" << endl;
    cout << "2 6 8 3 1 7 4" << endl;
    cout << "2 3 6 8 1 7 4" << endl;
    cout << "1 2 3 6 8 7 4" << endl;
    cout << "1 2 3 6 7 8 4" << endl;
    cout << "1 2 3 4 6 7 8" << endl;
    
    //Question 2
    // Change the less than sign (<) in between arr[current] and arr[current -1] 
    // into a greater than sign (>) and the array will be organized in descending order


    double average = 0;
    //Question 3
    cout << "Q3" << endl;
    
    
    
    planetSort();

    //Q4
    cout << "Q4" << endl;

    insertion(elements, size);
    int middle = size/2;

    if(size % 2 == 1) {
        average = elements[middle];
    }
    else {
        average = (elements[middle-1]+elements[middle])/2;
    }

    cout << average;

    //Question 5
    //insertion sorting is a form of stable sorting. 
    //In insertion sorting, an element is picked and swapped with another
    //values are not swapped when two meet the equality condition


}