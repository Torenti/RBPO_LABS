#include <iostream>
#include <string>
using namespace std;

extern string strGlobalSalary;
extern unsigned short height;

void ReadPersonData(string& _name, unsigned short& _age, double& _salary);
void ReadPersonData(string& _name, unsigned short& _age, unsigned short& height, unsigned short& _weight);
void WritePersonData(const string& _name, const string& _height, const string& _weight, const unsigned short* _age);

int main(int argc, char** argv)
{
	unsigned short weight, age;
	string strHeight, strWeight;
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

