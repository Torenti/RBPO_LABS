#include <iostream>
#include <string>
using namespace std;

string ReadPersonName();
unsigned short ReadPersonAge();
void ReadPersonSalary(double* _salary);
void ReadPersonHeight();
void ReadPersonWeight(unsigned short& _weight);

void ReadPersonData(string& _name, unsigned short& _age, double& _salary)
{
	cout << "Input name: ";
	_name = ReadPersonName();
	cout << "Input age: ";
	_age = ReadPersonAge();
	cout << "Input salary: ";
	ReadPersonSalary(&_salary);
}

void ReadPersonData(string& _name, unsigned short& _age, unsigned short& height, unsigned short& _weight)
{
	cout << "Input name: ";
	_name = ReadPersonName();
	cout << "Input age: ";
	_age = ReadPersonAge();
	cout << "Input height: ";
	ReadPersonHeight();
	cout << "Input weight: ";
	ReadPersonWeight(_weight);
}