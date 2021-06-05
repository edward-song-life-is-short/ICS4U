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

string words[20000];

int counter = 0;

void mergeSort(string arr[], int size, int start, int mid, int end)
{
    string *tempArray = new string[size];

    int pos1 = start;
    int pos2 = mid + 1;
    int moveSpot = start;

    while (!(pos1 > mid && pos2 > end))
    {
        if ((pos1 > mid) || ((pos2 <= end) && (arr[pos2] < arr[pos1])))
        {
            tempArray[moveSpot] = arr[pos2];
            pos2 += 1;
        }
        else
        {
            tempArray[moveSpot] = arr[pos1];
            pos1 += 1;
        }
        moveSpot += 1;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = tempArray[i];
    }
}

void arrayMerge(string arr[], int start, int end, int size)
{
    counter++;
    if (start < end)
    {
        int mid = (start + end) / 2;
        arrayMerge(arr, start, mid, size);
        arrayMerge(arr, mid + 1, end, size);
        mergeSort(arr, size, start, mid, end);
    }
}

int main()
{
    int size;
    string word;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> word;
        words[i] = word;
    }

    arrayMerge(words, 0, size-1, size);

    cout << counter << endl;

    for(int i = 0; i < size; i++) {
        cout << words[i] << " ";
    }
}