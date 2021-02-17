//hw4.cpp
#include <iostream>
using namespace std;
// Please provide the matrix class 
class matrix
{
private:
	int size;
	int ** matrix_p;
public:
	void setElement(int i, int j, int value);
	int  getElement(int i, int j);
	void printSelf();

	matrix();
	matrix(int size);
	~matrix();
	matrix(const matrix& m);
	matrix& operator=(const matrix& m);
};

int main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				m->setElement(i, j, 10);
			else
				m->setElement(i, j, 1);
		}

	// show the matrix on the screen
	cout << "m = " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m->getElement(i, j) << " ";

		cout << endl;
	}


	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator


	//show the testing matrix objects
	cout << "m1 = " << endl;
	m1.printSelf();
	cout << "*m2 = " << endl;
	m2->printSelf();
	cout << "m3 = " << endl;
	m3.printSelf();


	// delete the dynamic allocated object
	delete m;
	delete[] mArr1;
	delete m2;
	system("pause");
	return 0 ;
}
void matrix::setElement(int i, int j, int value)
{
	this->matrix_p[i][j] = value;
}
int matrix::getElement(int i, int j)
{
	return this->matrix_p[i][j];
}
void matrix::printSelf()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << this->matrix_p[i][j] << " ";
		}
		cout << endl;
	}
}

matrix::matrix()
{
	int **matrix_p = new int *[1];
	matrix_p[0] = new int[1];
	this->size = 1;
	this->matrix_p = matrix_p;
}
matrix::matrix(int size)
{
	int **matrix_p = new int *[size];
	for (int i = 0; i < size; i++)
		matrix_p[i] = new int[size];
	this->size = size;
	this->matrix_p = matrix_p;
}
matrix::~matrix()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->matrix_p[i];
	delete[] this->matrix_p;
}
matrix::matrix(const matrix& other)
{
	int **matrix_p = new int *[other.size];
	for (int i = 0; i < other.size; i++)
		matrix_p[i] = new int[other.size];
	for (int i = 0; i < other.size; i++)
		for (int j = 0; j < other.size; j++)
			matrix_p[i][j] = other.matrix_p[i][j];
	this->size = other.size;
	this->matrix_p = matrix_p;
}
matrix& matrix::operator=(const matrix& other)
{
	for (int i = 0; i < this->size; i++)
		delete[] this->matrix_p[i];
	delete[] this->matrix_p;
	int **matrix_p = new int *[other.size];
	for (int i = 0; i < other.size; i++)
		matrix_p[i] = new int[other.size];
	for (int i = 0; i < other.size; i++)
		for (int j = 0; j < other.size; j++)
			matrix_p[i][j] = other.matrix_p[i][j];
	this->size = other.size;
	this->matrix_p = matrix_p;
	return *this;
}





