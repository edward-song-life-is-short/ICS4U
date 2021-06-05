#include <iostream>
using namespace std;
#include <ctime>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

void q1a() {
    int row, column;
    int **matrix; //two * are needed because it is a pointer to a pointer
    
    cout << "please enter the dimesion of the matrix" << endl;
    
    cin >> row;
    cin >> column;
    
    matrix=new int*[row]; //creates a new array of pointers to int objects for rows
    
    for(int i=0; i<row; ++i)
        matrix[i]= new int[column];//creates new 'column' number of locations
    
    cout << "enter the elements of the array " << endl;
    
    for ( int i= 0; i<row; i++)
        for ( int j=0; j<column; j++)
            cin>>matrix[i][j];
    
    for (int r=0; r<row; r++){
        for (int c = 0; c< column; c++)
            cout << matrix[r][c]<<"\t";
        cout << endl;
    }
    
    for (int r=0; r<row; r++){
        delete[] matrix[r]; //deallocate each pointer within the pointer array
    }
    
    delete[] matrix; //deallocate the pointer
}

void q1b() {
    int row, column;
    int **matrix; //two * are needed because it is a pointer to a pointer
    
    cout << "please enter the dimesion of the matrix" << endl;
    
    cin >> row;
    cin >> column;
    
    int total = row * column;
    int sum = 0;

    matrix=new int*[row]; //creates a new array of pointers to int objects for rows
    
    for(int i=0; i<row; ++i)
        matrix[i]= new int[column];//creates new 'column' number of locations
    
    for(int i= 0; i<row; i++) {
        for ( int j=0; j<column; j++) {
            matrix[i][j] = rand() % 100 + 1;
            sum+=matrix[i][j];
        }
    }

    int average = sum/total;
    
    cout << "The average is: " << average << endl;

    for (int r=0; r<row; r++){
        delete[] matrix[r]; //deallocate each pointer within the pointer array
    }
    
    delete[] matrix; //deallocate the pointer
}

void q1c() {
    int n;

    int** two_d_array;

    cout << "Enter the dimensions for NxN square" << endl;
    cin >> n;

    two_d_array = new int*[n];

    for(int i=0; i<n; ++i)
        two_d_array[i]= new int[n];//creates new 'column' number of locations
    
    cout << "Enter the values for the square from top - bottom, left to right" << endl;
    for(int i= 0; i<n; i++) {
        for ( int j=0; j<n; j++) {
            cin>> two_d_array[i][j];
        }
    }

    for(int k = 0; k<n; k++) {
        for(int p = 0; p < n; p++) {
            if(p == k) {
                cout << "This value is in the main diagonal:" << endl;
                cout << two_d_array[k][p] << endl;
            }
        }
    }

    for (int r=0; r<n; r++){
        delete[] two_d_array[r]; //deallocate each pointer within the pointer array
    }
    
    delete[] two_d_array; //deallocate the pointer
}

void q2() {
    int columns, rows1, rows2;
    cout << "Enter the number of columns for 2 2-d arrays:" << endl;
    cin >> columns;

    cout << "Enter the number of rows for the first array:" << endl;
    cin >> rows1;

    cout << "Enter the number of rows for the second array:" << endl;
    cin >> rows2;

    int** first_array, **second_array, **third_array;

    first_array = new int*[rows1];
    second_array = new int*[rows2];

    for(int i=0; i<rows1; ++i)
        first_array[i]= new int[columns];//creates new 'column' number of locations
    
    for(int i = 0; i < rows2; i++)
        second_array[i] = new int[columns];
    
    cout << "Enter the elements for the first array:" << endl;

    for(int i= 0; i<rows1; i++) {
        for ( int j=0; j<columns; j++) {
            cin>> first_array[i][j];
        }
    }

    cout << "Enter the elements for the second array:" << endl;
    for(int k = 0; k < rows2; k++) {
        for(int j = 0; j < columns; j++) {
            cin >> second_array[k][j];
        }
    }


    //combine the two arrays
    int total_rows = rows1+rows2;

	third_array = new int*[total_rows];

    for(int i=0; i<total_rows; i++) {
		third_array[i]= new int[columns];//creates new 'column' number of locations
	}

    for(int k = 0; k < total_rows; k++) {
        for(int p = 0; p < columns; p++) {
            if(k <= rows1 -1) {
                third_array[k][p] = first_array[k][p];
            }
            else {
                third_array[k][p] = second_array[k-rows1][p];
            }
        }  
    }

    cout << "The elements of the third array are:" << endl;
    
    for(int i = 0; i < total_rows; i++) {
        for(int t = 0; t < columns; t++) {
            cout << third_array[i][t] << "\t";
           
        }   
		cout << endl;
    }

    for (int r=0; r<rows1; r++){
        delete[] first_array[r]; //deallocate each pointer within the pointer array
    }

     for (int r=0; r<rows2; r++){
        delete[] second_array[r]; //deallocate each pointer within the pointer array
    }
     for (int r=0; r<total_rows; r++){
        delete[] third_array[r]; //deallocate each pointer within the pointer array
    }
    
    delete[] first_array; //deallocate the pointer
    
    delete[] second_array; //deallocate the pointer
    
    delete[] third_array; //deallocate the pointer
}

//question 3
using namespace std;
void modifyArray (int[], int);
void modifyElement(int);

void modifyArray(int b[], int ArraySize){
    for(int i = 0; i < ArraySize; i++) {
        b[i]*=2;
    }
}

void modifyElement(int a)
{
    a*=2;
}

int main() {
    q1a();
    q1b();
    q1c();
    q2();

    int element[5];

    for (int index =0; index <= 4; index++)
        element[index] = index;
    
    cout << "Effects of passing entire array call by reference\n\n";
    cout << "Value of the original array is \n";
    for (int x = 0; x <= 4; x++)
        cout << element[x] << " ";
    
    cout << endl;
    
    cout << "Modified array values:" << endl;
    modifyArray (element, 5);

    for(int i = 0; i < 5; i++) {
        cout << element[i] << endl;
    }

    cout << endl << endl;
    
    cout << "Effects of passing array element call-by-value\n\n";
    cout << "The value of element[3] is " << element[3] << endl;
    
    modifyElement(element[3]);
    
    cout << "The value of element[3] is " << element[3] << endl;
    return 0;

}