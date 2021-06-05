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

int elements[10000];

void quickSort(int list[], int low, int high)
{
    int moveL = 0;
    int moveR = 1;

    if (low < high)
    {
        int left = low;
        int right = high;
        int location = moveL;
        int pivot = list[low];
        cout << pivot << " " << "[" << left << " " << right << "]" << endl;
        
        
        cout << endl;
        while (left < right)
        {
            if (location == moveL)
            {
                while ((list[right] >= pivot) && (left < right))
                    right--;

                list[left] = list[right];
                location = moveR;
            }
            if (location == moveR)
            {
                while ((list[left] <= pivot) && (left < right))
                    left++;

                list[right] = list[left];
                location = moveL;
            }
        }
        

        for(int i = 0; i < high; i++) {
            cout << list[i] << " ";
        }
        
        list[left] = pivot; // or list[right] = pivot, since left == right
        quickSort(list, low, left - 1);
        quickSort(list, right + 1, high);

        
    }
}

void quickSort(int list[], int size)
{
    quickSort(list, 0, size - 1);
}

int main()
{
    int size, element;
    cin >> size;

    for(int i = 0; i < size; i++) {
        cin >> element;
        elements[i] = element;
    }

    quickSort(elements, size);

    for(int i = 0; i < size; i++) {
        cout << elements[i] << " ";
    }
}