#pragma once
#include "Person.h"

class Node{
    private:
    //This could be any data type
    Person *p;
    //This will be a pointer for the next Node
    Node *next;
    public:
    //Basic constructors
    Node();
    Node(Person *p);
    Node(Person *p, Node* next);

    //Basic accessor method
    Person* getPerson();
    Node *getNext();
    
    //Basic setter method
    void setPerson(Person *p);
    void setNext(Node *next);
};