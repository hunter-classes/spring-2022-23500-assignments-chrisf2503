#pragma once
#include "Node.h"
class Olist{
    private:
    Node *head;

    public:
    //constructor
    Olist();
    //Deconstructor 
    ~Olist();
    //insterting an node
    void insert(int val);
    //returning the values within nodes
    std::string toString();
    //If it has that value (true) or not (false)
    bool contain(int val);
    //Getting a val at that certain location
    std::string get(int loc);
    //removing a Node at a specific location
    void remove(int loc);
    //reverse the order of a node*/
    void reverse();
};