#include "ListFine.h"


ListFine::ListFine()
{
    firstNode = nullptr;
    lastNode = nullptr;
    length = 0;
}

int ListFine::getLenght()
{
    return length;
}

void ListFine::add(Fine fine)
{
    if (length == 0) {
        firstNode = new Node();
        firstNode->fine = fine;
        lastNode = firstNode;
    }
    else {
        Node* temp = lastNode;
        lastNode = new Node();
        lastNode->fine = fine;
        temp->nexNode = lastNode;
    }
    length++;
}

void ListFine::add(string number, string name, int prise)
{
    if (length == 0) {
        firstNode = new Node();
        firstNode->fine.setNumber(number);
        firstNode->fine.setName(name);
        firstNode->fine.setPrise(prise);
        lastNode = firstNode;
    }
    else {
        Node* temp = lastNode;
        lastNode = new Node();
        lastNode->fine.setNumber(number);
        lastNode->fine.setName(name);
        lastNode->fine.setPrise(prise);
        temp->nexNode = lastNode;
    }
    length++;
}

void ListFine::print()
{
    Node* currentNode = firstNode;
    for (int i = 0; i < length; i++) {
        currentNode->fine.print();
        currentNode = currentNode->nexNode;
    }
    cout << endl;
}
