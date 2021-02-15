//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;



void main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the matrix and vector."<<endl;
	cin>>size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	for(i=0; i<size; i++)
		v->setElement(i,i+1);


	//show the matrix and vector on the screen
	cout<<"m = "<<endl;
	for(i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}

	cout<<"v = "<<endl;
	for(i=0; i<size; i++)
		cout<<v->getElement(i)<<" ";

	cout<<endl;

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
	vector& ans1 = MmultV(*m,*v);
	cout<<"ans1="<<endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v,*m);
	cout<<"ans2="<<endl;
	ans2.printSelf();


	//test counting object
	cout<<"You have create "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;
	delete v;
	delete [] vArr1;
	delete v2;

	//test counting object
	cout<<"After deleting, there are "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;
}

