
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


int fib(int n) {

    if(n<=1) 
        return n;
    
    return fib(n - 1) + fib(n-2);

}

int main() {
    int n;

    cin >> n;
    
    int number;

    number = fib(n);

    cout << number;





}