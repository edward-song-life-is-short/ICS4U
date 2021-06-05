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


void two(int twoPower[], int index, int value) {
    
    if(index < 0) {
        return;
    }
    else {
        two(twoPower, index -1, value/2);
    }
    twoPower[index] = value;

}

int main() {
    

    int n;

    cin >> n;
    
    int *twoPower = new int[n];

    two(twoPower, n, pow(n, 2));

    for(int i = 0; i < n; i++) {
        cout << twoPower[i] << " ";
    }

    delete[] twoPower;

}