#include <iostream>
#include "ListFine.h"
#include "Fine.h"
#include "Tree.h"
using namespace std;

int main()
{
    
    Tree tree;     
    Fine fine;    
    tree.Add(fine);
    tree.Add(fine);
    fine.setNumber("a123aa");
    tree.Add(fine);
    tree.Add(fine);
    fine.setNumber("a133aa");
    tree.Add(fine);
    tree.Add(fine);
    fine.setNumber("a124aa");
    tree.Add(fine);
    tree.Add(fine);
    tree.Print(tree.getTree());

}
