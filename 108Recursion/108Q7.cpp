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

unsigned long long gcd(unsigned long long num1, unsigned long long num2) {
    unsigned long long gcd;
    
    for(int i = 1; i <= num2 && i <= num1; i++) {
        if(num1%i== 0 && num2%i == 0) {
            gcd = i;
        }
    }

    return gcd;
}


unsigned long long fractorial(unsigned long long n) {
  
    if(n==1){
        return 1;
    }
    
        unsigned long long test = fractorial(n-1);
        return (test * n)/gcd(test, n);
    
}

int main() {
    unsigned long long number;
    cin >> number;

    unsigned long long fractorialNum = 0;

    fractorialNum = fractorial(number);
    cout << fractorialNum;
    
}