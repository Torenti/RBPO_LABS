#include <iostream>
#include <string>
using namespace std;

unsigned short height;
string strGlobalSalary;

unsigned short ReadPersonAge()
{
	unsigned short age;
	cin >> age;
	return age;
}
string ReadPersonName()
{
	string name;
	cin >> name;
	return name;
}
void ReadPersonHeight()
{
	cin >> height;
}
void ReadPersonWeight(unsigned short& _weight)
{
	cin >> _weight;
}
void ReadPersonSalary(double* _salary)
{
	cin >> *(_salary);
}
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

void WritePersonData(const string& _name,
	const string& _height = "",
	const string& _weight = "",
	const unsigned short* _age = 0)
{
	cout << "------------------------------" << endl;
	cout << "Name: " << _name << endl;
	cout << "Height: " << _height << endl;
	cout << "Weight: " << _weight << endl;
	cout << "Age: " << *(_age) << endl;
	cout << "Salary: " << strGlobalSalary << endl;
	cout << "------------------------------" << endl;
}

#ifndef DO_NOT_DEFINE_MAIN
int main(int argc, char** argv)
{
	unsigned short weight, age;
	string strHeight, strWeight ;
	string name;
	double salary;

	ReadPersonData(name, age, salary);
	strGlobalSalary = to_string(salary);
	WritePersonData(name, strHeight, strWeight, &age);
	ReadPersonData(name, age, height, weight);
	WritePersonData(name, strHeight = to_string(height),
		strWeight = to_string(weight), &age);

	return 0;
}
#endif
