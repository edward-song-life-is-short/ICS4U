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



int gcd(int small, int big, int gcdN, int n) {
    if(n == 0) {
        return gcdN;
    }
    else {
        if(small%n == 0 && big%n == 0) {
            gcdN = n;
        }
        
        return gcd(small, big, gcdN, n--);
    }
}

int main() {
    int x, y, gcdN;

    cin >> x;
    cin >> y;

    if(x > y) {
        gcdN = gcd(y, x, 1, y);
    }
    else {
        gcdN = gcd(x, y, 1, x);
    }

    cout << gcdN;

    
}