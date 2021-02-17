//hw6.cpp
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;
class matrix;
class vector;
vector & MmultV(matrix&, vector&);
vector & VmultM(vector&, matrix&);

class matrix {
private:
	static int count;
	// add data members
	int **matrix_p;
	int size;

public:
	matrix(void) {
		this->count++;
		this->size = 0;
	}

	// add functiom members
	matrix(int size) {
		this->count++;
		this->size = size;
		matrix_p = new int*[size];
		for (int tmp = 0; tmp < size; tmp++) {
			matrix_p[tmp] = new int[size];
		}
	}

	//copy constructor
	matrix(const matrix &other) {
		this->count++;
		this->size = other.size;
		this->matrix_p = new int*[this->size];
		for (int tmp = 0; tmp < this->size; tmp++) {
			this->matrix_p[tmp] = new int[this->size];
			memcpy(this->matrix_p[tmp], other.matrix_p[tmp], this->size * sizeof(int));
		}
	}

	//copy assignment operator
	matrix &operator=(const matrix &other) {
		if (this != &other) {
			if (this->size > 0) {
				for (int tmp = 0; tmp < this->size; tmp++) {
					delete[] this->matrix_p[tmp];
				}
				delete[] this->matrix_p;
			}
			this->size = other.size;
			this->matrix_p = new int*[this->size];
			for (int tmp = 0; tmp < this->size; tmp++) {
				this->matrix_p[tmp] = new int[this->size];
				memcpy(this->matrix_p[tmp], other.matrix_p[tmp], this->size * sizeof(int));
			}
		}
		return *this;
	}

	~matrix(void) {
		this->count--;
		if (this->size > 0) {
			for (int tmp = 0; tmp < this->size; tmp++) {
				delete[] this->matrix_p[tmp];
			}
			delete[] this->matrix_p;
		}
		this->size = 0;
	}

	void setElement(int x, int y, int value) {
		this->matrix_p[x][y] = value;
	}


	int getElement(int x, int y) {
		return this->matrix_p[x][y];
	}

	void printSelf(void) {
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				cout << this->matrix_p[i][j] << " ";
			}
			cout << endl;
		}
	}

	static int getCount() {
		return count;
	}

	friend vector & MmultV(matrix&, vector&);
	friend vector & VmultM(vector&, matrix&);
};

class vector {
private:
	static int count;
	// add data members
	int *vector_p;
	int size;

public:
	vector(void) {
		this->count++;
		this->size = 0;
	}

	// add functiom members
	vector(int size) {
		this->count++;
		this->size = size;
		vector_p = new int[size];
	}

	//copy constructor
	vector(const vector &other) {
		this->count++;
		this->size = other.size;
		this->vector_p = new int[this->size];
		memcpy(this->vector_p, other.vector_p, this->size * sizeof(int));
	}

	//copy assignment operator
	vector &operator=(const vector &other) {
		if (this != &other) {
			if (this->size > 0) {
				delete[] this->vector_p;
			}
			this->size = other.size;
			this->vector_p = new int[this->size];
			memcpy(this->vector_p, other.vector_p, this->size * sizeof(int));
		}
		return *this;
	}
	~vector(void) {
		this->count--;
		if (this->size > 0) {
			delete[] this->vector_p;
		}
		this->size = 0;
	}
	void setElement(int i, int value) {
		this->vector_p[i] = value;
	}
	int getElement(int i) {
		return this->vector_p[i];
	}
	void printSelf(void) {
		for (int i = 0; i < this->size; i++) {
			cout << this->vector_p[i] << " ";
		}
		cout << endl;
	}

	static int getCount() {
		return count;
	}

	friend vector & MmultV(matrix&, vector&);
	friend vector & VmultM(vector&, matrix&);
};

vector & MmultV(matrix &m, vector &v) {
	int tmp;
	vector *v_tmp = new vector(v.size);
	for (int i = 0; i < v.size; i++) {
		tmp = 0;
		for (int j = 0; j < m.size; j++) {
			tmp += m.matrix_p[i][j] * v.vector_p[j];
		}
		v_tmp->setElement(i, tmp);
	}
	return *v_tmp;
}

vector & VmultM(vector &v, matrix &m) {
	return MmultV(m, v);
}

int matrix::count = 0;
int vector::count = 0;

int main() {
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the matrix and vector." << endl;
	cin >> size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				m->setElement(i, j, 10);
			}
			else {
				m->setElement(i, j, 1);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		v->setElement(i, i + 1);
	}

	//show the matrix and vector on the screen
	cout << "m = " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << m->getElement(i, j) << " ";
		}
		cout << endl;
	}

	cout << "v = " << endl;
	for (int i = 0; i < size; i++) {
		cout << v->getElement(i) << " ";
	}
	cout << endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor
	m1 = *m;						//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor
	vector vArr2[5];				//calling default constructor
	vector v1;						//calling default constructor
	vector* v2 = new vector(*v);	//calling copy constructor
	vector v3 = vector(*v);			//calling copy constructor
	v1 = *v;						//calling copy assignment operator


	//test MmultV and VmultM
	vector& ans1 = MmultV(*m, *v);
	cout << "ans1=" << endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v, *m);
	cout << "ans2=" << endl;
	ans2.printSelf();


	//test counting object
	cout << "You have create " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;


	// delete the dynamic allocated object
	delete m;
	delete[] mArr1;
	delete m2;
	delete v;
	delete[] vArr1;
	delete v2;

	//test counting object
	cout << "After deleting, there are " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;

	system("pause");
}

