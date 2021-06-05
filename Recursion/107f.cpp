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

int sum(int index, int arr[]) {
    
    if(index == 1) {
		return arr[0];
    }
    
    return sum(index-1, arr) + arr[index-1];
	   

}

int iterative(int arr[], int size) {
    int sum = 0;
    
    for(int i = 0; i < size; i++) {
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int n, elements;

    
    cin >> n;
    int *arr = new int[n];
   
    for(int i = 0; i < n; i++) {
        cin >> elements;
        arr[i] = elements;
    }

    cout << sum(n, arr);

    delete[] arr;

}