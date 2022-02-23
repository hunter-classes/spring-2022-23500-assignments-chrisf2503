#include <iostream>
#include "Node.h"

int main(){
    Node *p1 = new Node();
    p1 = new Node("current");
    //currently not pointing to another Node
    std::cout << p1->getData() << '\n';
    Node *p2 = new Node("values");
    std::cout << p2->getData() << '\n';
    std::cout << '\n';
    //now p1 is has the address of p2
    p1->setNext(p2);
    std::cout << p1->getData() << '\n';
    std::cout << p1->getNext()->getData() << '\n';
    /*
    p1address       p1Data      p2Address     p2Data    pointing to nothing
    [100] -------> ["current"][150] -------> ["values"][nullpointer]
    */
    std::cout << '\n';
    Node *p3 = new Node("within");
    p2->setNext(p3);
    Node *p4 = new Node("List");
    p3->setNext(p4);
    Node *list = p1;
    //deleting p2
    while(list != nullptr){
        std::cout << list->getData() << '\n';
        list = list->getNext();
    }
    return 0;
}