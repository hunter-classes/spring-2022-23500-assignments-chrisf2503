#pragma once
#include "Node.h"

class List{
    private:
    Node *head;
    public:
    List();
    ~List();
    void insert(int data);
    void insert(int loc, int data);
    void remove(int loc);
    std::string toString();
    int length();
    int get(int loc);
};