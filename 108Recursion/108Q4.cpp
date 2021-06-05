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

string reverse(string input, int iterate) {
    if(iterate == input.length()) {
        char x[2];

        x[0] = input[iterate];
        return x;
    }
    else {
        return reverse(input, iterate+1) + input[iterate];
    }
}

bool isPalindrome(string input, int iterate, int counter, string reverse) {
    
    if(counter == input.length() - 1) {
        return true;
    }
    else if(iterate == input.length() - 1) {
        return false;
    }
    else {
        if(input[iterate] == reverse[iterate]) {
            counter++;
        }
        
        return isPalindrome(input, iterate + 1, counter, reverse);
    }
}


int main() {
    string input;
    
    getline(cin, input);

    string revString = "";
    
    revString = reverse(input, 0);

    cout << revString << endl;

    string newR, newI;

    for(int i = 0; i < revString.length(); i++) {
        if(revString[i] != ' ') {
            newR += tolower(revString[i]);
        }
        if(input[i] != ' ') {
            newI += tolower(input[i]);
        }

    }

    bool check = isPalindrome(newI, 0, 0, newR);

    if(check) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    
}

