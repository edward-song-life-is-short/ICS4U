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



int sequence1(int term, int value) {
    if(term == 1) {
        return value;
    }
    else {
        return sequence1(term - 1, value - 2);
    }
}

int sequence2(int term, int value) {
    if(term == 1) {
        return value;
    }
    else {
        return sequence2(term - 1, value*2);
    }
}

int main() {
    int term;

    cin >> term;

    int seq1 = sequence1(term, 3);
    int seq2 = sequence2(term, -1);

    cout << seq1 << endl;
    cout << seq2;
    
}