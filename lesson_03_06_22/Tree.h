#pragma once
#include "ListFine.h"



class Tree
{
private:
	Node *root;
public:
	struct Node {
		string key;
		ListFine list;
		Node* parent, * left, * right;
	};
	Tree();
	~Tree();
	//������ �� ���������� ����
	void Print(Node* node);
	//����� �� ���������� ����
	Node* Search(Node* node, string key);
	//��������� ��� ���������� ����
	Node* Next(Node* node);
	//���������� ��� ���������� ����
	Node* Previous(Node* node);
	//������� ����
	void Insert(Node* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Node* z = 0);
	//�������� ������
	Node* GetRoot();
	//min �� ���������� ����
	Node* Min(Node* node);
	//max �� ���������� ����
	Node* Max(Node* node);

};

