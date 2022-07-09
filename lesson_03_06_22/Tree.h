#pragma once
#include "ListFine.h"
#include <iostream>
#include <string>

class Nodes {
public:
	string key;
	ListFine list;
	Nodes* parent, * left, * right;
	Nodes();
};

class Tree
{
private:
	Nodes* root;
public:	
	Tree();	
	void Print(Nodes* node);
	void Print(string key);
	void Add(Fine fine);
	Nodes* getTree();
};

