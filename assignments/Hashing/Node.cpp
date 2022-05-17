#include <iostream>
#include "Node.h"
#include "Person.h"

Node::Node() : next(nullptr){
}

Node::Node(Person *p){
    this->p = p;
    this->next = nullptr;
}

Node::Node(Person *p, Node *next){
    this->p = p;
    this->next = next;
}

Person* Node::getPerson(){
    return p;
}

Node *Node::getNext(){
    return this->next;
}

void Node::setPerson(Person *p){
    this->p = p;
}

void Node::setNext(Node *next){
    this->next = next;
}