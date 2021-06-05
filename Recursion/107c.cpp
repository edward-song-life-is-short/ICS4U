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


void print(int arr[], int n, int iterate) {

    if(iterate == n) {
        return;
    }

    cout << arr[iterate] << " ";

    print(arr, n, iterate + 1);
}

int main() {
    int array[20000];

    int n, elements;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> elements;
        array[i] = elements;
    }
    
    print(array, n, 0);


}