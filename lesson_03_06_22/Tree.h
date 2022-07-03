#pragma once
#include "ListFine.h"

struct Node {
	string key;
	ListFine list;
	Node* parent, * left, * right;
};

class Tree
{
private:
	Node *root;
public:
	
	Tree();
	~Tree();
	//печать от указанного узла
	void Print(Node* node);
	//поиск от указанного узла
	Node* Search(Node* node, string key);
	//следующий для указанного узла
	Node* Next(Node* node);
	//предыдущий для указанного узла
	Node* Previous(Node* node);
	//вставка узла
	void Insert(Node* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Node* z = 0);
	//получить корень
	Node* GetRoot();
	//min от указанного узла
	Node* Min(Node* node);
	//max от указанного узла
	Node* Max(Node* node);

};

