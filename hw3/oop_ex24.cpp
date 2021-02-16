/*	oop_ex24.cpp
	dynamic 2D array using new and delete */


#include <iostream>

using namespace std;

void main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix using new
	int** m = new int*[size];

	for(int i=0; i<size; i++)
		m[i] = new int[size];

	// assign the values to the created matrix
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			m[i][j] = i+j;

	// show the matrix on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m[i][j]<<" ";

		cout<<endl;
	}

	// release the matrix using delete
	for(int i=0; i<size; i++)
		delete [] m[i];

	delete [] m;

	system("pause");
}

