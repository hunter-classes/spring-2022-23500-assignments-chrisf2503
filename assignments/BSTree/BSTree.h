#pragma once
#include "Node.h"

class BSTree{
    private:
        Node* root;
        int height;
    public:
        BSTree();
        std::string traverse(Node *n);
        std::string get_debug_String();
        void insert(int data);  
        void setup();
        int rsearch(int value);
        int rsearch(int value, Node* p);
        Node* findMinNode(Node* current);
        void delNode(int val);
        //int treeHeight();
        //int treeHeight(Node *p);
};  