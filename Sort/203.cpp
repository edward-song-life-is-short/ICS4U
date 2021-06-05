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

void selectSort(string arr[], int n) {
    int pos_max; 
    string temp;

    for(int i = n-1; i > 0; i--) {
        
        
        pos_max = 0;

        for(int j=1; j<=i;j++) {
            if(arr[j]>arr[pos_max]) {
                pos_max=j;
            }
        }
        
        temp=arr[i];
        arr[i]=arr[pos_max];
        arr[pos_max] = temp;
        
        for(int t = 0; t < n; t++) {
            cout << arr[t] << " ";
        }
        cout << endl;
        
        
    }
}

void selectSort(int arr[], int n, int k) {
    int pos_max; 
    int temp;
    int counter = 0;

    for(int i = n-1; i > 0; i--) {
        pos_max = 0;

        for(int j=1; j<=i;j++) {
            if(arr[j]>arr[pos_max]) {
                pos_max=j;
            }
        }
        
        temp=arr[i];
        arr[i]=arr[pos_max];
        arr[pos_max] = temp;

        counter++;
        if(counter == k) {
            break;
        }
    }
}



void sortSmall(int arr[], int n) {
    int pos_max; 
    int temp;

    for(int i = 0; i < n; i++) {
         
         for(int t = 0; t < n; t++) {
            cout << arr[t] << " ";
        }
        cout << endl;
        pos_max = n-1;

        for(int j=n-1; j>=i;j--) {
            if(arr[j]<arr[pos_max]) {
                pos_max=j;
            }
        }

        temp=arr[i];
        arr[i]=arr[pos_max];
        arr[pos_max] = temp;

        

    }
}

int sortedK[20000];

int main() {
    int n;
    int elements;
    int k;

    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++) {
        cin >> elements;
        sortedK[i] = elements;
    }

    //Question 1
    string names[5] = {"Robert", "Brian", "Victor", "David", "Scott"};
    cout << "Q1" << endl;
    for(int i = 0; i < 5; i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    selectSort(names, 5);

    cout << endl;

    //Question 2
    //the question would sort in reverse alphabetical order from z-a
    
    //Question 3
    //a)An if statement can be added checking if the next bigger number is equal to 
    // pos_max, if this happens, the for loop can continue so the swap does not occur
    //b) This case occurs quite rarely in unorganized lists and so the extra comparison
    // can increase runtime 

    //Question 4
    int numbers[6]={8, 9, 6, 1, 2, 4};
    
    cout << "Q4" << endl;

    sortSmall(numbers, 6);
    
    //Question 5
    cout << "Q5" << endl;
    
    
    selectSort(sortedK, n, k);

    for(int i = 0; i < n; i++) {
        cout << sortedK[i] << " ";
    }
    cout << endl;
    
}