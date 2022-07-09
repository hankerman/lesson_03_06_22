#pragma once
#include "Fine.h"

struct Node
{
	Fine fine;
	Node* nexNode;
};

class ListFine
{
private:
	Node* firstNode;
	Node* lastNode;
	int length;
public:
	ListFine();
	int getLenght();
	void add(Fine fine);
	void add(string number, string name, int prise);
	void print();
};

