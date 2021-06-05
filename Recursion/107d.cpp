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


void init_array(int random[], int n, int iterate) {
    
    if(iterate == n) {
        return;
    }
    

    random[iterate] = rand()%50+1;
    cout << random[iterate] << " ";

    init_array(random, n, iterate + 1);
}

int main() {
    int *array;
    int random[10];

    int n = 10;

    init_array(random, n, 0);

    for(int i = 0; i < n; i++) {
        cout << random[i] << " ";
    }

}