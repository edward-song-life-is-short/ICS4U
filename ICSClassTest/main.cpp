#include <iostream>
#include "Villan.h"
#include <random>

//function to find the smallest difference between target and array value
int closerValue(int v1, int v2, int tar) {
	if (tar - v1 >= v2 - tar)
        return v2;
    else
        return v1;
}

//set min value to the first index, swap first value with any values in preceding elements if they are larger
//once the lowest value has been sorted into min index, the min index is increased to sort that value 
void selectionSort(Villan arr[], int n)
{
    int i, min;
 
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (int co = i+1; co < n; co++)
        if (arr[co].getPlanet() < arr[min].getPlanet())
            min = co;
 
        //swapping min element
		Villan temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
    }
}

//bubble sort 

//checks the adjacent elements that are side by side and swaps them if they are out of order
//passes the array for n-1 times
void bubbleSort(Villan arr[], int n) {
    for (int i = 0; i < n-1; i++)    
		for (int g = 0; g < n-i-1; g++)
			if (arr[g].getStrength() > arr[g+1].getStrength()) {
				Villan temp = arr[g];
				arr[g] = arr[g+1];
				arr[g+1] = temp;
			}
				
}

void printVillanArr(Villan arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i].toString();
	}
}

//t is target value
int findClosestBin_Search(Villan arr[], int n, int t) {

	//if the value is less than or greater the smallest/biggest number
	if (t <= arr[0].getStrength())
			return arr[0].getStrength();
		if (t >= arr[n - 1].getStrength())
			return arr[n - 1].getStrength();
	
		
		int i = 0, co = n, mid = 0;
		
		
		while (i < co) {
			//find the middle of the array 
			mid = (i + co) / 2;
			
			//find mid value 
			if (arr[mid].getStrength() == t)
				return arr[mid].getStrength();
	
			//search left -> target is less than vil strength
			if (t < arr[mid].getStrength()) {
	
				//return closest value between two vil elements
				//checks if the target fits between the mid and previous element
				if (mid > 0 && t > arr[mid - 1].getStrength())
					return closerValue(arr[mid - 1].getStrength(),
									arr[mid].getStrength(), t);
	
				co = mid;
				cout << "mid1:" << mid << endl;
			}
			else { //search rght
				//check if value is sandwachied between mid and next closest value
				if (mid < n - 1 && t < arr[mid + 1].getStrength())
					return closerValue(arr[mid].getStrength(),
									arr[mid + 1].getStrength(), t);
				
				i = mid + 1;
				cout << "co:" << co << endl;
			}
		}
	

		return arr[mid].getStrength();
}

int main() {
	Villan *arr = new Villan[8];

	for(int i = 0; i < 8; i++) {
		Villan *temp = new Villan();

		int strength = rand() % 100;
		bool inf = rand() % 2;

		temp->setStrength(strength);
		temp->setInfectious(inf);

		arr[i] = *temp;
	}

	//printVillanArr(arr, 8);

	arr[0].setPlanet("Jupiter");
	
	arr[1].addStrength(6);
	arr[2].subtractStrength(1);

	arr[3].strengthUp(arr[0]);
	arr[4].reduce(arr[0]);

	arr[5] = Villan::create(arr[0], arr[1]);
	arr[6] = Villan::multiply(arr[0], arr[1]);
	
	arr[7] = Villan(arr[0].getStrength(), arr[0].getPlanet(), arr[0].getInfectious());

	cout << "Modified villains:" << endl;
	printVillanArr(arr, 8);


	for(int i = 0; i < 8; i++) {
		
	}
	
	bubbleSort(arr, 8);
	cout << "Strength Sorted:" << endl;
	
	for(int i = 0; i < 8; i++) {
		cout << arr[i].getStrength() << " ";
	}
	cout << endl;

	selectionSort(arr, 8);

	cout << "Planets:: Sorted" << endl;
	for(int i = 0; i < 8; i++) {
		cout << arr[i].getPlanet() << " ";
	}
	cout << endl;

	int v;

	cout << "Input a numerical value to find which villain has the closest strength:" << endl;
	
	cin >> v;
	
	//sort by strength
	bubbleSort(arr, 8);

	int closest = findClosestBin_Search(arr, 8, v);

	cout << "Closest Value to the input is: " << closest << endl;

	


	delete[] arr;


}