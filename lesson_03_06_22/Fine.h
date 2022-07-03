#pragma once
#include <string>
#include <iostream>
using namespace std;

class Fine
{
private:
	string number;
	int prise;
	string name;
public:
	Fine(string number, string name, int prise);
	Fine();
	void print();
	string getFine();
	void setNumber(string number);
	void setName(string name);
	void setPrise(int prise);
};

