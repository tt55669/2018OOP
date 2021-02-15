//hw3.cpp
#include <iostream>
using namespace std;
// add the matrix simple class/structure here
class matrix {
public:
	matrix(){}
	// add data members
	int size;
	int **matrix_p;
	// add functiom members
	void tranpose();
	void destroy();
	void init(int size);
};
void main()
{	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;
	// create the matrix object
	matrix m;
	// using init to setup the matrix object
	m.init(size);
	// assign the values to the created matrix
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m.matrix_p[i][j] = count;	//this will not work. correct it
			count++;
		}
	}
	// show the matrix on the screen
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m.matrix_p[i][j] << " ";	//this will not work. correct it

		cout << endl;
	}
	// call transpose() to calculate its transpose
	m.tranpose();
	// show the matrix after transpose on the screen
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m.matrix_p[i][j] << " ";	//this will not work. correct it

		cout << endl;
	}
	// call destroy to free the object
	m.destroy();
	system("pause");
}
void matrix::init(int size) {
	int data;
	this->size = size;
	matrix_p = new int*[size];
	for (data = 0; data < size; data++) {
		matrix_p[data] = new int[size];
	}
}
void matrix::tranpose() {
	int  i, j, save;
	if (this->size == 0) return;
	for (i = 0; i < this->size; i++) {
		for (j = 0; j < i; j++) {
			save = matrix_p[i][j];
			matrix_p[i][j] = matrix_p[j][i];
			matrix_p[j][i] = save;
		}
	}
}
void matrix::destroy() {
	int p;
	if (this->size == 0) return;
	for (p = 0; p < this->size; p++) {
		delete[] matrix_p[p];
	}
	delete[] matrix_p;
	this->size = 0;
}

