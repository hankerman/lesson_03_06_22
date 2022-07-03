#include "Fine.h"

Fine::Fine(string number, string name, int prise)
{
	this->number = number;
	this->name = name;
	this->prise = prise;
}

Fine::Fine() : Fine("o000oo", "name", 500)
{
}

void Fine::print()
{
	cout << number << "\t" << name << "\t" << prise << endl;
}

string Fine::getFine()
{
	return number;
}

void Fine::setNumber(string number)
{
	this->number = number;
}

void Fine::setName(string name)
{
	this->name = name;
}

void Fine::setPrise(int prise)
{
	this->prise = prise;
}
