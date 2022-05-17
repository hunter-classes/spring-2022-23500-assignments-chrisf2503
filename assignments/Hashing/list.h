#pragma once
#include "Node.h"
#include "Person.h"
class List{
    private:
    Node *head;
    public:
    List();
    ~List();
    void insert(Person *p);
    void insert(int loc, Person *p);
    void remove(int loc);
    std::string toString();
    int length();
    Person* get(int loc);
};