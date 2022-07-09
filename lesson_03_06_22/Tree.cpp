#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

void Tree::Print(Nodes* node)
{
	
	if (node != 0)
	{
		Print(node->left);
		node->list.print();
		Print(node->right);
	}
}

void Tree::Add(Fine fine)
{
	if (root == nullptr) {
		root = new Nodes;
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

Nodes::Nodes()
{
	this->key = " ";
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}
