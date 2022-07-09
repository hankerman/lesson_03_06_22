#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
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
	//���� ���� ���� � ����� �� ���������
	while (node != 0 && node->key.find(key) != 0)
	{
		if (node->key.find(key) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

void Tree::Add(Fine fine)
{
	if (root == nullptr) {
		root = new Node;
		root->key = fine.getFine();
		root->list.add(fine);
		root->parent = nullptr;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		while (root != 0 && root->key.find(fine.getFine()) != 0)
			{
			if (root->key.find(fine.getFine()) < 0)
				root = root->left;
			else
				root = root->right;
		}		
	}

}

Node::Node()
{
	this->key = " ";
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}
