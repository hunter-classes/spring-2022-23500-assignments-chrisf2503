#include <iostream>
#include "Person.h"
#include "Node.h"
#include "list.h"

int main(){
    std::cout << "Basic Test\n";
    Person *p1 = new Person("Chris", "Flores", 208577940); 
    Person *student;
    List *l = new List();
    l->insert(p1);
    std::cout << l->toString() << '\n';
    return 0;
}