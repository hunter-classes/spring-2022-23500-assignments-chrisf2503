#pragma once
#include "Node.h"

class BSTree{
    private:
        Node* root;
    public:
        BSTree();
        std::string get_debug_String();
        void insert(int data);  
        void setup();
};