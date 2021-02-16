#include <iostream>
using namespace std;

/*
 *                   Biological е═кл 
 *                   /     \
 *                  /       \
 *                 /         \
 *              Animal        Plant
 *              / \          /   \
 *             /   \        /     \
 *            /     \      /       \
 *       Fish      Bird    Tree    Grass 
 */
class Biological
{
public:
	Biological();
	~Biological();
	Biological(string name, bool canMove);
	Biological(const Biological& obj);
	Biological& operator=(const Biological& obj);

	virtual void print();

	bool canMove;
	string name;
};

Biological::Biological()
{
	cout << "Biological class default constructor" << endl;
	this->name = "Biological";
	this->canMove = false;
}

Biological::~Biological()
{
	cout << "Biological class destructor" << endl;
}

Biological::Biological(string name, bool canMove)
{
	cout << "Biological class user-defined constructor" << endl;
	this->name = name;
	this->canMove = canMove;
}

Biological::Biological(const Biological& obj)
{
	cout << "Biological class copy constructor" << endl;
	this->name = obj.name;
	this->canMove = obj.canMove;
}

Biological& Biological::operator=(const Biological& obj)
{
	cout << "Biological class copy assignment operator" << endl;
	this->name = obj.name;
	this->canMove = obj.canMove;

	return *this;
}

void Biological::print()
{
	cout << "name : " << this->name << endl;
	cout << "canMove : " << this->canMove << endl;
}

class Animal : public Biological
{
public:
	Animal();
	~Animal();
	Animal(string name, bool canMove, bool canSwim);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	
	virtual void print();

	
	bool canSwim;
};

Animal::Animal()
{
	cout << "Animal class default constructor" << endl;
	this->name = "Animal";
	this->canMove = true;
	this->canSwim = false;
}

Animal::~Animal()
{
	cout << "Animal class destructor" << endl;
}

Animal::Animal(string name, bool canMove, bool canSwim) : Biological(name, canMove)
{
	cout << "Animal class user-defined constructor" << endl;
	this->canSwim = canSwim;
}

Animal::Animal(const Animal& obj) : Biological(obj)
{
	cout << "Animal class copy constructor" << endl;
	this->canSwim = obj.canSwim;
}

Animal& Animal::operator=(const Animal& obj)
{
	Biological::operator=(obj);
	cout << "Animal class copy assignment operaotr" << endl;
	this->canSwim = obj.canSwim;

	return *this;
}

void Animal::print()
{
	Biological::print();

	cout << "canSwim : " << this->canSwim << endl;
}

class Plant : public Biological
{
public:
	Plant();
	~Plant();
	Plant(string name, bool canMove, string size);
	Plant(const Plant& obj);
	Plant& operator=(const Plant& obj);

	virtual void print();
	string size;
};

Plant::Plant()
{
	cout << "Plant class default constructor" << endl;
	this->name = "Plant";
	this->size="";
}

Plant::~Plant()
{
	cout << "Plant class destructor" << endl;
}

Plant::Plant(string name, bool canMove, string size) : Biological(name, canMove)
{
	cout << "Plant class user-defined constructor" << endl;
	this->name = name;
	this->size =size;
}

Plant::Plant(const Plant& obj) : Biological(obj)
{
	cout << "Plant class copy constructor" << endl;
	this->size = obj.size;
}

Plant& Plant::operator=(const Plant& obj)
{
	Biological::operator=(obj);
	cout << "Plant class copy assignment operaotr" << endl;
	this->size = obj.size;

	return *this;
}

void Plant::print()
{
	Biological::print();
	cout << "size : " << this->size << endl;
}

class Fish : public Animal
{
public:
	Fish();
	~Fish();
	Fish(string name);
	Fish(const Fish& obj);
	Fish& operator=(const Fish& obj);
	void swim(void);
};

Fish::Fish()
{
	cout << "Fish class default constructor" << endl;
	this->name = "Fish";
	this->canSwim = true;
}

Fish::~Fish()
{
	cout << "Fish class destructor" << endl;
}

Fish::Fish(string name) : Animal(name,true, true)
{
	cout << "Fish class user-defined constructor" << endl;
}

Fish::Fish(const Fish& obj) : Animal(obj)
{
	cout << "Fish class copy constructor" << endl;
}

Fish& Fish::operator=(const Fish& obj)
{
	Animal::operator=(obj);
	cout << "Fish class copy assignment operaotr" << endl;

	return *this;
}
void Fish::swim(void)
{
	cout << "I can swim." << endl;
}

class Bird : public Animal
{
public:
	Bird();
	~Bird();
	Bird(string name);
	Bird(const Bird& obj);
	Bird& operator=(const Bird& obj);
	void fly(); 
};

Bird::Bird()
{
	cout << "Bird class default constructor" << endl;
	this->name = "Bird";
	this->canSwim = false;
}

Bird::~Bird()
{
	cout << "Bird class destructor" << endl;
}

Bird::Bird(string name) : Animal(name, true, false)
{
	cout << "Bird class user-defined constructor" << endl;
}

Bird::Bird(const Bird& obj) : Animal(obj)
{
	cout << "Bird class copy constructor" << endl;
}

Bird& Bird::operator=(const Bird& obj)
{
	Animal::operator=(obj);
	cout << "Bird class copy assignment operaotr" << endl;

	return *this;
}

void Bird::fly(void)
{
	cout << "I can fly." << endl;
}

class Tree : public Plant
{
public:
	Tree();
	~Tree();
	Tree(string name);
	Tree(const Tree& obj);
	Tree& operator=(const Tree& obj);
	void tree(void);
};

Tree::Tree()
{
	cout << "Tree class default constructor" << endl;
	this->name = "Tree";
}

Tree::~Tree()
{
	cout << "Tree class destructor" << endl;
}


Tree::Tree(string name) : Plant(name, 0, "Big" )
{
	cout << "Tree class user-defined constructor" << endl;
}

Tree::Tree(const Tree& obj) : Plant(obj)
{
	cout << "Tree class copy constructor" << endl;
}

Tree& Tree::operator=(const Tree& obj)
{
	Plant::operator=(obj);
	cout << "Tree class copy assignment operaotr" << endl;

	return *this;
}
void Tree::tree(void)
{
	cout << "I am a tree." << endl;
}

class Grass : public Plant
{
public:
	Grass();
	~Grass();
	Grass( string name);
	Grass(const Grass& obj);
	Grass& operator=(const Grass& obj);
	void grass(void);
};

Grass::Grass()
{
	cout << "Grass class default constructor" << endl;
	this->name = "Grass";
}

Grass::~Grass()
{
	cout << "Grass class destructor" << endl;
}

Grass::Grass(string name) : Plant(name,false,"small")
{
	cout << "Grass class user-defined constructor" << endl;
}

Grass::Grass(const Grass& obj) : Plant(obj)
{
	cout << "Grass class copy constructor" << endl;
}

Grass& Grass::operator=(const Grass& obj)
{
	Plant::operator=(obj);
	cout << "Grass class copy assignment operaotr" << endl;

	return *this;
}
void Grass::grass(void)
{
	cout << "I am a grass." << endl;
}


int main()
{
	/* Biological class test */
	{
		Biological Biological_a;
		Biological Biological_b("Biological",false);
		Biological Biological_c(Biological_b);
		Biological Biological_d;
		Biological_d = Biological_c;

		cout << "-------------------" << endl;
		// Biological_d.makeNoise();
		Biological_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	{
		Animal Animal_a;
		Animal Animal_b("Animal",false, false);
		Animal Animal_c(Animal_b);
		Animal Animal_d;
		Animal_d = Animal_c;

		cout << "-------------------" << endl;
		Animal_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Plant class test */
	{
		Plant Plant_a;
		Plant Plant_b("Plant",false,"small");
		Plant Plant_c(Plant_b);
		Plant Plant_d;
		Plant_d = Plant_c;

		cout << "-------------------" << endl;
		Plant_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Fish class test */
	{
		Fish Fish_a;
		Fish Fish_b("Fish");
		Fish Fish_c(Fish_b);
		Fish Fish_d;
		Fish_d = Fish_c;

		cout << "-------------------" << endl;
		Fish_d.swim();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Bird class test */
	{
		Bird Bird_a;
		Bird Bird_b("Bird");
		Bird Bird_c(Bird_b);
		Bird Bird_d;
		Bird_d = Bird_c;

		cout << "-------------------" << endl;
		Bird_d.fly();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Tree class test */
	{
		Tree Tree_a;
		Tree Tree_b("Tree");
		Tree Tree_c(Tree_b);
		Tree Tree_d;
		Tree_d = Tree_c;

		cout << "-------------------" << endl;
		Tree_d.tree();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Grass class test */
	{
		Grass Grass_a;
		Grass Grass_b("Grass");
		Grass Grass_c(Grass_b);
		Grass Grass_d;		
		Grass_d = Grass_c;

		cout << "-------------------" << endl;
		Grass_d.grass();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Polymorphism test */
	{
		Biological biological("Biological",0);
		Animal animal("Animal",0, 0);
		Plant plant("Plant",0,"small");
		Fish fish("Fish");
		Bird bird("Bird");
		Tree tree("Tree");
		Grass grass("Grass");

		Biological *biological_arr[] = { &biological, &animal, &plant, &fish, &bird, &tree, &grass};
		
		cout << "-------------------" << endl;
		for (int i = 0; i < 7; i++) {
			biological_arr[i]->print();
			cout<<endl;
		}
		cout << "-------------------" << endl;
	}
}
