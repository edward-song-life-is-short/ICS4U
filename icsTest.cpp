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
#include <sys/timeb.h>
#include <iomanip>

void q1()
{
    cout << " 52 31 73 27 77 66 98 23 30 44 55 41";

    //a.
    //pivot element is 52, swap values using left and right markers
    cout << " 23 31 41 27 44 30 52 98 66 77 55 73";

    //b.
    //find the smallest value and put it in the beginning swapping its position
    //since the smallest value is already at the front, the first pass does not swap anything
    cout << "23 31 41 27 44 30 52 98 66 77 55 73";

    //c.
    //find largest value
    //compare 2 values, swap if they are the same
    cout << "23 31 27 41 30 44 52 66 77 55 73 98";

    //d.
    //find largest value
    //sort all 4-sorted lists
    //make 4 different sub lists of every 4 elements
    //sort those sub lists
    //nothing to sort since bubble sort has made the list very
    // close to sorted
    cout << "23 31 27 41 30 44 52 66 77 55 73 98";

    //e.
    //sort 2k lists
    //make a sublist of every two values, and sort accordingly
    //there are only 2 sublists, merge them, putting each element
    //back into their respective spaces
    cout << "23 31 27 41 30 44 52 55 73 66 77 98";
}

int powerSums(int base, int power)
{
    int sum = 0;

    for (int i = power; i >= 0; i--)
    {
        sum += pow(base, i);
        base++;
    }
    return sum;
}

int recursivePowerSums(int base, int power)
{
    if (power < 0)
    {
        return 0;
    }
    else
    {
        return recursivePowerSums(base + 1, power - 1) + pow(base, power);
    }
}

int closestValue(int n1, int n2, int value)
{
    if (value - n1 >= n2 - value)
        return 1; //we know n2 is closer
    else
        return 0; // we know n1 is closer
}

int binarySearchLoop(int arr[], int value, int n)
{
    int start = 0, end = n;
    int middle = 0;

    int rank, predecessor, successor, neighbor;

    if (value < arr[0])
    {
        rank = 1;
        predecessor = -1;
        successor = arr[1];

        cout << rank << " " << predecessor << " " << successor << " " << successor << endl; 
        return rank;
    }

    if (value > arr[n - 1])
    {
        rank = n;
        successor = -1;
        predecessor = arr[n-1];
        cout << rank << " " << predecessor << " " << successor << " " << predecessor << endl; 
        return rank;
    }

    while (start < end)
    {
        middle = (start + end) / 2;

        if (value == arr[middle])
        {
            rank = middle+1;
            break;
        }
        else if (value < arr[middle])
        {

            if (middle > 0 && value > arr[middle - 1])
            {
                if (closestValue(arr[middle - 1], arr[middle], value) == 1)
                {
                    rank = middle + 1;
                    neighbor = arr[middle];
                }
                else
                {
                    rank = middle;
                    neighbor = arr[middle-1];
                }
                break;
            }

            end = middle;
        }
        else
        {
            if (middle < n - 1 && value < arr[middle +1])
            {
                if (closestValue(arr[middle], arr[middle+1], value) == 1)
                {
                    rank = middle+1;
                    neighbor = arr[middle+1];
                }
                else
                {
                    rank = middle;
                    neighbor = arr[middle];
                }
                break;
            }
            start = middle + 1;
            

        }

        
    }
    
    predecessor = arr[rank-2];
    successor = arr[rank+1];

    cout << rank << " " << predecessor << " " << successor << " " << neighbor << endl; 
    return rank;
}

void q3()
{
    int size;

    cin >> size;

    int t1, t2;
    cin >> t1;
    cin >> t2;

    int element;
    int *array = new int(size);

    for (int i = 0; i < size; i++)
    {
        cin >> element;
        array[i] = element;
    }

    int start = binarySearchLoop(array, t1, size) - 1;
    int end = binarySearchLoop(array, t2, size) + 1;

    int range = end - start;
    cout << range << endl;

}

void q2()
{
    cout << "Q2" << endl;

    int power, base;
    cin >> base;
    cin >> power;

    cout << powerSums(base, power) << endl;
    cout << recursivePowerSums(base, power) << endl;
}

int main()
{
    cout << "Q1" << endl;
    q1();
    cout << "Q2" << endl;
    q2();
     cout << "Q3" << endl;
    q3();
}