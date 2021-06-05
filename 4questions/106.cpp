#include<iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

bool numbers[200000];

int main()
{
    int input = 0;

    cin >> input;

    for (int i = 2; i <= input; i++)
    {
        if (numbers[i] == 0)
        {
            for (int k = i * i; k <= input; k += i)
            {
                numbers[k] = 1;
            }
        }
    }

    for (int i = 2; i <= input; i++)
    {
        if (numbers[i] == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}