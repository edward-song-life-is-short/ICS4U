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


void decimalToBinary(int n) {
  
    if(n == 0) {
        return;
    }
    else {
        decimalToBinary(n/2);
        cout << n%2;
    }
}

int main() {
    int number;
    cin >> number;

    if(number != 0)
        decimalToBinary(number);
    
    else 
        cout << 0;
     ;
}