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

int elements[20000];
int randoms[10000];

void q1q2()
{
    cout << "Q1" << endl;
    cout << "19 18 21 22 29 26 37 26 41 63 47 61 72 55" << endl;
    cout << "Q2" << endl;
    cout << "19 18 21 22 29 26 37 26 41 55 47 61 72 63" << endl;
}

int kDecrease(int k) {
    return (k - 1) / 3;
}

int kGenerate(int size)
{
    int arrK = 1;

    while (arrK <= size/3)
    {
        arrK = arrK * 3 + 1;
    }

    arrK = kDecrease(arrK);
    return arrK;
}

void kSortSublist(int arr[], int k, int start, int length)
{
    for (int top = start + k; top < length; top = top + k)
    {
        int item = arr[top]; //temporary store for current item
        int i = top;
        while (i > start && item < arr[i - k])
        {
            // shift larger items to the right by k
            arr[i] = arr[i - k];
            // prepare to check the next item, k spaces left
            i = i - k;
        }
        arr[i] = item; // put sorted item in open location
    }
}

void generateRndArrray(int random[]) {
    
    for(int i = 0; i < 10000; i++) {
        int num = rand() % 999 + 1;
        random[i] = num;
    }
}

int testKdecrease(int k, int multiple, int constant) {
    return (k - constant)/multiple;
}

int testK(int size, int multiple, int constant) {
    int kTest = 1;

    while(kTest <= size) {
        kTest = kTest * multiple + constant;
    }

    testKdecrease(kTest, multiple, constant);
    return kTest;
}

void sort(int arr[], int largeK, int size) {
    while(largeK >= 1) {
        cout << largeK << "k sort list:" << endl;
        
        for(int i = 0; i < largeK; i++) {
            kSortSublist(arr, largeK, i, size);
        }

        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";

            if((i+1)%10==0 && i!=size-1) {
                cout << endl;
            }
        }

        largeK = kDecrease(largeK);
        // largeK = testKdecrease(largeK, 3, 2);
        
        cout << endl;
        cout << endl;

        
    }
}

// void q6() {
//     srand(0);
    
//     int multiple = 3;
//     int constant = 1;

//     int largek = testK(10000, multiple, constant);

//     generateRndArrray(random);
//     sort(random, largek, 10000);
// }

int main()
{
    int size;
    int element;

    cin >> size;

    for(int i = 0; i < size; i++) {
        cin >> element;
        elements[i] = element;
    }

    q1q2();

     //Question 3
    //Since shell sort has preliminary steps, decreasing the k value
    //when k = 1, the shell sort will have less sorting to do and will
    //swap less values because the list is already somewhat sorted
    //as a result, the argument is case dependent on array size and how well the
    // elements are ordered. If the array is very large with unordered elements,
    //shell sort will be faster than insertion sort because of sublist sorting
    // insertion sort will have to swap hundreds and thousands of values in order to
    // properly sort the array
    
    cout << "Q5" << endl;

    int largeK = kGenerate(size);

    sort(elements, largeK, size);

    //Q6
    // Testing sorting a random array of 10000 elements
    // The normal equation for k is 3k+1, so we can experimetn with different k values by adjusting the 
    // equation, I will try 5 different tests, changing the equation


    // double start = clock();

    // ios_base::sync_with_stdio(false);

    // q6();

    // double end = clock();

    // cout << "time:" << (end-start)/double(CLOCKS_PER_SEC)*1000 << endl;
    /*


    Equations              Time (ms)
    -----------           -------
    2k+1                    10    
    2k+2                    12
    3k+2                    15
    4k                      17
    k+5                     17
    3k+1                     6

    The timed searched do show the k value as the most ideal
    */

   
}