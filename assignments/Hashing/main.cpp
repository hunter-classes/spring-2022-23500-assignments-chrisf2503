#include <iostream>
#include "Person.h"
#include "Node.h"
#include "list.h"
#include "Dictionary.h"
int main(){
    std::cout << "Basic Test\n";
    Person *p1 = new Person("Chris", "Flores", 208577940); 
    Person *p2 = new Person("Kuya", "Lee", 209832049);
    Person *p3 = new Person("David", "Garcia", 242018420);
    Person *p4 = new Person("Stacy", "Cool", 294303840); 
    Person *p5 = new Person("Vero", "Pena", 293484038);
    Person *p6 = new Person("Sharlyn", "Rodriguez", 243590358);
    Person *student;
    List *l = new List();
    l->insert(p1);
    std::cout << l->toString() << '\n';
    Dictionary *dic = new Dictionary();
    std::cout << dic->hashing(p1) << '\n';
    std::cout << dic->hashing(p2) << '\n';
    std::cout << dic->hashing(p3) << '\n';
    std::cout << dic->hashing(p4) << '\n';
    std::cout << dic->hashing(p5) << '\n';
    std::cout << dic->hashing(p6) << '\n';
    dic->insert(p1);
    dic->insert(p2);
    dic->insert(p3);
    dic->insert(p4);
    dic->insert(p5);
    dic->insert(p6);
    student = dic->getPerson(208577940);
    std::cout << student->get_name() << '\n';
    dic->getAllKeys();
    return 0;
}