#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main(){
    std::cout << "part1:\n";
    Node* t = new Node(10);
    std::cout << t->getData() << '\n'; 
    Node* t1 = new Node(20);
    t->setLeft(t1);
    std::cout << t->getLeft()->getData() << '\n';
    t1 = new Node(30);
    t->getLeft()->setLeft(t1);
    std::cout << t->getLeft()->getData() << '\n'; 
    t1 = new Node(40);
    t->getLeft()->getLeft()->setLeft(t1);
    std::cout << t->getLeft()->getLeft()->getData() << '\n'; 
    t1 = new Node(50);
    t->setRight(t1);
    std::cout << t->getRight()->getData()<< '\n';
    t1 = new Node(60);
    t->getRight()->setLeft(t1);
    std::cout << t->getRight()->getLeft()->getData() << '\n';
    t1 = new Node(70);
    t->getRight()->setRight(t1);
    std::cout << t->getRight()->getRight()->getData() << '\n';
    std::cout << "part2:\n";
    BSTree* tree = new BSTree();
    tree->setup();
    std::cout << tree->get_debug_String() << '\n';
    std::cout << tree->rsearch(20) << '\n';
    //tree->delNode(20);
    return 0;
}