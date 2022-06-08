#include<iostream>
#include<string>
#include<time.h>
using namespace std;

struct IPrint {
	virtual void Print() = 0;
};

struct IInput {
	virtual void Input() = 0;
};

//Figure
class Figure : public IPrint, public IInput {
protected:
	int a;
public:
	virtual void Print() {
		cout << a;
	}
	virtual void Input() {
		cout << "width: " << a << endl;
	}
	virtual void S() = 0;
};

class Triangle : public Figure {
protected:
	int a, b, c;
public:
	virtual void Print() {
		cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
	}
	virtual void Input() {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;
	}
	void S() {
		cout << "Square: " << (a / 2) * (b + c) << endl;
	}
};

class Square : public Figure {
protected:
	int a, b;
public:
	virtual void Print() {
		cout << "a: " << a << ", b: " << b << endl;
	}
	virtual void Input() {
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
	}
	void S() {
		cout << "Square: " << a * b << endl;
	}
};

class Circle : public Figure {
protected:
	const int Pi = 3.14;
	int r;
public:
	virtual void Print() {
		cout << "r: " << r << "Pi: " << Pi << endl;
	}
	virtual void Input() {
		cout << "a: ";
		cin >> a;
	}
	void S() {
		cout << "Square: " << Pi * r * r << endl;
	}
};

//Car

class Car : public IInput, public IPrint {
protected:
	string model;
public:
	virtual void Print() {
		cout << "Model: " << model << endl;
	}
	virtual void Input() {
		cout << "Model: ";
		cin >> model;
	}
	void virtual Speed() = 0;
};

class Truck : public Car {
protected:
	string model;
	int size;
public:
	virtual void Print() {
		cout << "Model: " << model << endl;
		cout << "Size: " << size << endl;
	}
	virtual void Input() {
		cout << "Model: ";
		cin >> model;
		cout << "Size: ";
		cin >> size;
	}
	void virtual Speed() {
		cout << "Speed: " << rand() % 100 + 30 << endl;
	}
};

class Airplane : public Car {
protected:
	string model;
	int size;
	int length;
public:
	virtual void Print() {
		cout << "Model: " << model << endl;
		cout << "Size: " << size << endl;
		cout << "Length: " << length << endl;
	}
	virtual void Input() {
		cout << "Model: ";
		cin >> model;
		cout << "Size: ";
		cin >> size;
		cout << "Length: ";
		cin >> length;
	}
	void virtual Speed() {
		cout << "Speed: " << rand() % 1000 + 300 << endl;
	}
};

//Human

class Human : public IInput, public IPrint {
protected:
	string name;
	string surname;
public:
	virtual void Print() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
	}
	virtual void Input() {
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
	}
	void virtual Age() = 0;
};

class Programmer : public Human {
protected:
	string name;
	string surname;
	int skill;
public:
	virtual void Print() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Skill (1/10): " << skill << endl;
	}
	virtual void Input() {
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
		cout << "Skill(1/10): ";
		cin >> skill;
	}
	void virtual Age() {
		cout << "Age: " << rand() % 100 << endl;
	}
};

class Admin : public Human {
protected:
	string name;
	string surname;
	int skill;
	string gender;
public:
	virtual void Print() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Gender: " << gender << endl;
		cout << "Skill (1/10): " << skill << endl;
	}
	virtual void Input() {
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
		cout << "Skill(1/10): ";
		cin >> skill;
		cout << "Gender: ";
		cin >> gender;
	}
	void virtual Age() {
		cout << "Age: " << rand() % 100 << endl;
	}
};


//Functions

void MyInput(IInput* ptr) {
	ptr->Input();
}

void MyPrint(IPrint* ptr) {
	ptr->Print();
}



int main() {
	srand(time(0));

	IInput* obj1 = new Triangle();
	MyInput(obj1);
	obj1 = new Square();
	MyInput(obj1);
	obj1 = new Circle();
	MyInput(obj1);
	obj1 = new Airplane();
	MyInput(obj1);
	obj1 = new Truck();
	MyInput(obj1);
	obj1 = new Programmer();
	MyInput(obj1);
	obj1 = new Admin();
	MyInput(obj1);

	IPrint* obj2 = new Triangle();
	MyPrint(obj2);
	obj2 = new Square();
	MyPrint(obj2);
	obj2 = new Circle();
	MyPrint(obj2);
	obj2 = new Airplane();
	MyPrint(obj2);
	obj2 = new Truck();
	MyPrint(obj2);
	obj2 = new Programmer();
	MyPrint(obj2);
	obj2 = new Admin();
	MyPrint(obj2);


}