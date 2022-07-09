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
	Nodes* tmp = root;
	if (root == nullptr) {
		root = new Nodes;
		root->key = fine.getFine();
		root->list.add(fine);
		root->parent = nullptr;
		root->left = nullptr;
		root->right = nullptr;		
	}
	else {
		
		int chek = 0;
		Nodes* previous = root;
		Nodes* predprevious = previous;		
		Nodes* temp;
		temp = new Nodes;
		temp->key = fine.getFine();
		temp->list.add(fine);
		temp->parent = nullptr;
		temp->left = nullptr;
		temp->right = nullptr;
		do{
			if (tmp->key == fine.getFine()) {
				tmp->list.add(fine);
				break;
			}
			if (temp->key < previous->key) {
				previous = tmp;
				previous->parent = predprevious;
				predprevious = predprevious->left;
				tmp = tmp->left;
				chek = 1;
			}
			else {
				previous = tmp;
				previous->parent = predprevious;
				predprevious = predprevious->right;
				tmp = tmp->right;
				chek = 2;
			}
		} while (tmp != nullptr);
		if (previous->key != fine.getFine()) {			
			if (chek == 1) {
				previous->left = temp;
			}
			else {
				previous->right = temp;
			}			
		}
	}
}

Nodes* Tree::getTree()
{
	return root;
}

Nodes::Nodes()
{
	this->key = " ";
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}
