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
	//���� ���� ���� � ����� �� ���������
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
		//���� ���� ������ �������
		if (node->right != 0)
			return Min(node->right);
		//�������� ����
		y = node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && node == y->right)
		{
			//�������� �����
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
		//���� ���� ����� �������
		if (node->left != 0)
			return Max(node->left);
		//�������� ����
		y = node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && node == y->left)
		{
			//�������� �����
			node = y;
			y = y->parent;
		}
	}
	return y;
}

void Tree::Insert(Node* z)
{
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	Node* y = NULL;
	Node* node = root;
	//����� �����
	while (node != 0)
	{
		//������� ��������
		y = node;
		if (z->key.find(node->key) < 0)
			node = node->left;
		else
			node = node->right;
	}
	//��������� ��������
	z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (z->key.find(node->key) < 0)
		y->left = z;
	else
		y->right = z;
}

void Tree::Del(Node* z)
{
	//�������� �����
	if (z != 0)
	{
		Node* node, * y;
		//�� 2 �������
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
		//��������� �������� ����?
		if (y->parent == 0)
			root = node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = node;
		else
			//������ �� ��������?
			y->parent->right = node;
		if (y != z)
		{
			//����������� ������ ����
			z->key = y->key;
			z->list = y->list;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

Node* Tree::GetRoot()
{
	return root;
}

Node* Tree::Min(Node* node)
{
	//����� ������ "������" ����
	if (node != 0)
		while (node->left != 0)
			node = node->left;
	return node;
}

Node* Tree::Max(Node* node)
{
	//����� ������ "�������" ����
	if (node != 0)
		while (node->right != 0)
			node = node->right;
	return node;
}
