// C++ program to generate odd sized magic squares
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <string.h>

using namespace std;

void square(int n, int sum)
{
	
	//magic constant = x(x*x+1)/2
	//sum = (x^3 + x)/2
	
	//find sum of row of normal magic square where number starts at 1
	//divide difference between sum magic constant and normal magic square to find the range of numbers of the magic square by n size
	//simply add the difference/n and add it to the normal magic square to find the range of numbers that sum up to sum
	int increment = 0, normalSum = 0; 


	int **matrix;
    matrix = new int *[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            matrix[i][k] = 0;
        }
    }

    int y = 0, x = n / 2; 

    for (int k = 1; k <= n*n; ++k)
    {
        matrix[y][x] = k;

        y--;
        x++;

        if (k % n == 0)
        {
            y += 2;
            x--;
        }
        else
        {
            if (x == n)
                x -= n;
            else if (y < 0)
                y += n;
        }
    }

	for(int i = 0; i < n; i++) {
		normalSum+=matrix[0][i];
	}
	cout << normalSum << endl;

	increment = (sum - normalSum)/n;
	
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << matrix[i][k] + increment << " ";
        }
        cout << endl;
    }
    cout << endl;

	
}

int main()
{
    int n, sum;
    cin >> n;
    cin >> sum;

    square(n, sum);

    return 0;
}