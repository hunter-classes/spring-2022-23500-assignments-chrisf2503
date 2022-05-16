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
    //deleting Node that points to one Node
    tree->delNode(3);
    std::cout << "Deleted 3\n" << tree->get_debug_String() << '\n';
    //Deleting node that points to nothing
    tree->delNode(2);
    std::cout << "Deleted 2\n" << tree->get_debug_String() << '\n';
    //Deleting Nodes that point to 2 things 
    tree->delNode(5);
    tree->delNode(20);
    std::cout << "Deleted 5 and 20\n" << tree->get_debug_String() << '\n';
    std::cout << "Part 3: \n";
    BSTree *tree2 = new BSTree();
    tree2->setup();
    std::cout << "The sum of first level: " << tree2->sums(1) << '\n';
    std::cout << "The sum of second level: " << tree2->sums(2) << '\n';
    std::cout << "The sum of third level: " << tree2->sums(3) << '\n';
    std::cout << "The Height is: " << tree2->getHeight() << '\n';
    std::cout << "Number 3 and 15 are ";
    if(tree2->cousin(5, 15)){
        std::cout << "COUSIN\n"; 
    }
    else{
        std::cout << "NOT COUSIN\n";
    }
    std::cout << "Number 3 and 30 are ";
    if(tree2->cousin(3, 30)){
        std::cout << "COUSIN\n"; 
    }
    else{
        std::cout << "NOT COUSIN\n";
    }
    
    return 0;
}