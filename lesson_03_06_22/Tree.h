#pragma once
#include "ListFine.h"
#include <iostream>
#include <string>

class Node {
public:
	string key;
	ListFine list;
	Node* parent, * left, * right;
	Node();
};

class Tree
{
private:
	Node* root;
public:
	
	Tree();	
	void Print(Node* node);
	void Print(string key);
	Node* Search(Node* node, string key);		
	void Add(Fine fine);	
};

