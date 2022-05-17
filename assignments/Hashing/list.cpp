#include <iostream>
#include "list.h"
#include "Node.h"
#include "Person.h"

List::List(){
    head = nullptr;
}
List::~List(){
    Node *trailer; 
    std::cerr << "Destructing\n";
    while(head!=nullptr){
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}
void List::insert(Person *p){
    //Fist create the new node
    Node *newNode = new Node(p);

    //trying to reconnnect to the other nodes
    newNode->setNext(head);
    head = newNode;
}
//We need a pointer before the insertion point
/*We use piggybacking
That is, sending a pointer one behind that trails 
the walker 
When walker points to nod en 
the trailer points to NOde n-1*/    
void List::insert(int loc, Person* p){
    Node *walker = head;
    Node *newNode = new Node(p);
    Node *trailer = nullptr;
    
    while (walker && loc > 0){
        trailer = walker;
        walker = walker->getNext();
        loc--;
    }
    //walker is at n, trailer is at the point before
    //the incerstion  point
    if(loc > 0){
        throw std::out_of_range("out of range");
    }

    if(trailer == nullptr){
        newNode->setNext(head);
        head = newNode;
    }
    else{
        newNode->setNext(walker);
        trailer->setNext(newNode);
    }
}

void List::remove(int loc){
    Node *walker = head;
    Node *trailer = nullptr;

    while(walker != nullptr && loc > 0){
        trailer = walker;
        walker = walker->getNext();
        loc--;
    }
    if(walker == nullptr){
        throw std::out_of_range("out of range");
    }
    if(trailer == nullptr){
        head = walker->getNext();
    }
    else{
        trailer->setNext(walker->getNext());
        delete walker;
    }
}
std::string List::toString(){
    Node *walker = head;
    std::string s = "";
    while(walker != nullptr){
        s += walker->getPerson()->info() + " --> " ;
        walker = walker->getNext();
    }
    s += "nullpointer";
    return s;
}

int List::length(){
    Node *walker = head;
    int count = 0;
    while (walker){
        count++;
        walker = walker->getNext();
    }
    return count;
}

Person* List::get(int loc){
  int result;
  Node *walker = head;

  // using walker as a boolean is
  // the same as writing walker != nullptr
  while (walker && loc > 0){
    walker = walker->getNext();
    loc--;
  }
  if (walker)
    return walker->getPerson();
  else
    throw 1;
}