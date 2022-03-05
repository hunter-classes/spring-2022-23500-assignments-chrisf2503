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
    if(head == nullptr || val < walker->getData()){
        newNode->setNext(head);
        head = newNode;
    }
    while(walker!=nullptr){
        track = walker;
        walker = walker->getNext();
        if(val > track->getData() && walker != nullptr){
            if(val < walker->getData()){
                newNode->setNext(walker);
                track->setNext(newNode);
            }
        }
        else if(val > track->getData() && walker == nullptr){
            newNode->setNext(walker);
            track->setNext(newNode);
        }
    }
}

std::string Olist::toString(){
    std::string output = "";
    Node *walker = head;
    while(walker != nullptr){
        output += std::to_string(walker->getData()) + " ---> ";
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

std::string Olist::get(int loc){
    Node *walker = head;
    while(walker && loc > 0){
        walker = walker->getNext();
        loc--;
    }
    if(walker){
        return std::to_string(walker->getData());
    }
    else{
        throw std::out_of_range("out of bound");
    }
}

void Olist::remove(int loc){
    Node *walker = head;
    Node *track = nullptr;
    while(walker != nullptr && loc > 0){
        track = walker;
        walker = walker->getNext();
        loc--;
    }
    if(walker == nullptr){
        throw std::out_of_range("out of range");
    }
    if(track == nullptr){
        head = walker->getNext();
    }
    else{
        track->setNext(walker->getNext());
        delete walker;
    }
}

void Olist::reverse(){
    Node *walker = head;
    head = nullptr;
    while(walker != nullptr){
        Node *replace = new Node(walker->getData());
        replace->setNext(head);
        head = replace;
        walker = walker->getNext();
    }
}//*/ 