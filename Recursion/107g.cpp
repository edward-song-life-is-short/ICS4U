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

int largest(int arr[], int index) {

    if(index==1) {
        return arr[0];
    }

    return max(arr[index-1], largest(arr, index-1));

}

int iterative(int arr[], int size) {
    int largest = -100000;

    for(int i = 0; i < size; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    
    int n, elements;

    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> elements;
        arr[i] = elements;
    }

    int largestNum = largest(arr, n);

    delete[] arr;

    cout << largestNum;
}