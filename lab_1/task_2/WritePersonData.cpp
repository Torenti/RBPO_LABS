#include <iostream>
#include <string>
using namespace std;

string strGlobalSalary;

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