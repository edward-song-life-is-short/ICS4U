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


double recursiveBirthday(double n) {
    double notProbability = 1;

    for(double i = 1; i < n; i++) {
        notProbability *= (365 - i) / 365;
    }

    return 1 - notProbability;
}

double iterativeBirthday(double n, double probability) {
    if(n == 0) {
        return  1 - probability;
    }
    else {
        return iterativeBirthday(n- 1, probability*=((365 - n)/365));
    }
}

int main() {
    double students;

    cin >> students;

    double probabilityR, probabilityI;

    probabilityR = recursiveBirthday(students);
    probabilityI = iterativeBirthday(students - 1, 1);

    cout << probabilityR;
    
}