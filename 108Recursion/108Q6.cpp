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

double elements[200000];

double average(int iterate) {
  
    if(iterate == 0) {
        return elements[0];
    }
    
      return ((average(iterate - 1) * iterate * 1.0) + elements[iterate])/(iterate + 1 * 1.0);
    
}

int main() {
    double element;
    int number;
    cin >> number;

    for(int i = 0; i < number; i++) {
        cin >> element;
        elements[i] = element;
    }

    double averages = round(average(number-1)*10)/10;
    cout << averages;
}