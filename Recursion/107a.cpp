
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


int exponents(int base, int power) {
    if(power != 0) {
        return(base * exponents(base, power - 1));

    }
    else {
        return 1;
    }
}

int main() {
    int base, exponent;

    cin >> base;
    cin >> exponent;
    
    int number;

    number = exponents(base, exponent);

    cout << number;





}