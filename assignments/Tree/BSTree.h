#pragma once
#include "Node.h"

class BSTree{
    private:
        Node* root;
        int total;
        int height;
        int numBranch;
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
        int sums(int level);
        void sums(int level, int currentLevl, Node *p);
        int getHeight();
        int calcHeight(Node *p, int h);
        bool cousin(int val1, int val2);
        int cousinLevel(int val, int level, Node *p);
        
};  