#include <iostream>
#include "Node.h"
#include "list.h"
#include "Olist.h"

int main(){
    Olist *l = new Olist();
    l->insert(1);
    l->insert(2);
    l->insert(-1);
    l->insert(-2);
    l->insert(0);
    l->insert(10);
    l->insert(5);
    std::cout << l->toString() << '\n';
    std::cout << "the number 3 is ";
    if(l->contain(3)){
        std::cout << "in the list\n";
    }
    else{
        std::cout << "not in the list\n";
    }
    std::cout << "But the number 2 is ";
    if(l->contain(2)){
        std::cout << "in the list\n";
    }
    else{
        std::cout << "not in the list\n";
    }
    for(int i = 0; i < 7; i++){
        std::cout << "Index " << i << ": " << l->get(i) << '\n';
    };
    l->remove(5);
    std::cout << l->toString() << '\n';
    l->reverse();
    std::cout << l->toString() << '\n';
    return 0;
}