#include <iostream>
#include "Olist.h"
#include "Node.h"

Olist::Olist(){
    head = nullptr;
}

Olist::~Olist(){
    Node *walker;

    while(head != nullptr){
        walker = head;
        head = head->getNext();
        delete walker;
    }
}

void Olist::insert(int val){
    Node *walker = head;
    Node *newNode = new Node(val);
    Node *track = nullptr;
    if(head == nullptr){
        newNode->setNext(head);
        head = newNode;
    }
    while(walker != nullptr){
        //Draw it out and then plan it we need a few condition

    }
}

std::string Olist::toString(){
    std::string output = "";
    Node *walker = head;
    while(walker != nullptr){
        output += walker->getData() + " ---> ";
        walker = walker->getNext();
    }
    output += "nullptr";
    return output;
}

bool Olist::contain(int val){
    Node *walker = head;

    while(walker != nullptr){
        if(walker->getData() == val){
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

/*void Olist::reverse(){
    Node *walker = head;
    head = nullptr;
    while(walker != nullptr){
        insert(walker->getData());
        walker = walker->getNext();
    }
}*/ 