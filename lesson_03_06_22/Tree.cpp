#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	Del();
}

void Tree::Print(Node* node)
{
	if (node != 0)
	{
		Print(node->left);
		node->list.print();
		Print(node->right);
	}
}

Node* Tree::Search(Node* node, string key)
{
	//ѕока есть узлы и ключи не совпадают
	while (node != 0 && (key.find(node->key)) != 0)
	{
		if (key.find(node->key) != 0)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

Node* Tree::Next(Node* node)
{
	Node* y = 0;
	if (node != 0)
	{
		//если есть правый потомок
		if (node->right != 0)
			return Min(node->right);
		//родитель узла
		y = node->parent;
		//если Node не корень и Node справа
		while (y != 0 && node == y->right)
		{
			//ƒвижемс€ вверх
			node = y;
			y = y->parent;
		}
	}
	return y;
}

Node* Tree::Previous(Node* node)
{
	Node* y = 0;
	if (node != 0)
	{
		//если есть левый потомок
		if (node->left != 0)
			return Max(node->left);
		//родитель узла
		y = node->parent;
		//если Node не корень и Node слева
		while (y != 0 && node == y->left)
		{
			//ƒвижемс€ вверх
			node = y;
			y = y->parent;
		}
	}
	return y;
}

void Tree::Insert(Node* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Node* y = NULL;
	Node* node = root;
	//поиск места
	while (node != 0)
	{
		//будущий родитель
		y = node;
		if (z->key.find(node->key) < 0)
			node = node->left;
		else
			node = node->right;
	}
	//заполн€ем родител€
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (z->key.find(node->key) < 0)
		y->left = z;
	else
		y->right = z;
}

void Tree::Del(Node* z)
{
	//удаление куста
	if (z != 0)
	{
		Node* node, * y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			node = y->left;
		else
			node = y->right;
		if (node != 0)
			node->parent = y->parent;
		//”дал€етс€ корневой узел?
		if (y->parent == 0)
			root = node;
		else if (y == y->parent->left)
			//слева от родител€?
			y->parent->left = node;
		else
			//справа от родител€?
			y->parent->right = node;
		if (y != z)
		{
			// опирование данных узла
			z->key = y->key;
			z->list = y->list;
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}

Node* Tree::GetRoot()
{
	return root;
}

Node* Tree::Min(Node* node)
{
	//ѕоиск самого "левого" узла
	if (node != 0)
		while (node->left != 0)
			node = node->left;
	return node;
}

Node* Tree::Max(Node* node)
{
	//ѕоиск самого "правого" узла
	if (node != 0)
		while (node->right != 0)
			node = node->right;
	return node;
}
