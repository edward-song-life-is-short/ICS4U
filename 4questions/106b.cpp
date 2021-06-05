#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>

void run(int row, int columns, int start, int end, int excess, int total) {
	// int top = 0, bottom = row - 1;
	// int left = 0, right = columns - 1;
	double convertR = row*1.0, convertC = columns*1.0;

	int centerX = ceil(convertR/2) - 1;
	int centerY = ceil(convertC/2) - 1 ;

	int **matrix;

	int fix = start;

	
	int t = centerX;
	int b = centerX + 1;

	int l = centerY;
	int r = centerY + 1;

	int finalCheck = 0;

	matrix = new int *[20000]; //creates a new array of pointers to int objects for rows

	for(int i = 0; i < row + 1; i++)
		matrix[i] = new int[20000];

	matrix[centerX][centerY] = fix;
 
	while(1) {

		for(int i = l; i <= r; i++ ) {
			fix++;
			matrix[b][i] = fix;
			finalCheck = fix;
		}	
		fix--;

		if(t > 0) {
			t--;
		}

	

		for(int i = b; i >= t; i--) {
			fix++;
			matrix[i][r] = fix;
			finalCheck = fix;
		}
		
		l--;

		
		
		fix--;
		
		

		for(int i = r; i >= l; i--) {
			fix++;
			
			if(fix <= end) {
				matrix[t][i] = fix;
			}
			finalCheck = fix;
		}
		fix--;
		b++;

		if(l < 0) {
			break;
		}

		for(int i = t; i <= b; i++) {
			fix++;
			matrix[i][l] = fix;

			finalCheck = fix;
		}

		fix--;
		r++;

		if(finalCheck > end) {
			break;
		}
		

	}

	for(int i = 0; i < row; i++) {
		for(int k = 0; k <= columns; k++) {
			
			if(matrix[i][k] <= end && matrix[i][k]!= 0) {
				cout << matrix[i][k] << " ";
			}
			else {
				cout << "   ";
			}

		}

		cout << endl;
	}
}

int main()
{
    int start, end;

	string temp;
	getline(cin, temp);
	cin >> start;
    getline(cin, temp);
	getline(cin, temp);
	cin >> end;

    int total = end - start + 1;

	

    int column = floor(sqrt(total));
    int excess = total % column;

	double convertT = total*1.0, convertC = column*1.0;

	int rows = ceil(convertT/convertC);
	run(rows, column, start, end, excess, total);
    
}