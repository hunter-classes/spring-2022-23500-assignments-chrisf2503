#include <iostream>
#include "BSTree.h"

BSTree::BSTree(){
    root = nullptr;
}

std::string BSTree::get_debug_String(){
    if(root == nullptr){
        return "";
    }else{
        return std::to_string(root->getData()) + " " +std::to_string(root->getLeft()->getData());
    }
}

void BSTree::insert(int data){

}

void BSTree::setup(){
    Node* n = new Node(10);
    root = n;
    n = new Node(20);
    root->setLeft(n);
    n = new Node(30);
    root->setRight(n);
    n = new Node(40);
    root->getLeft()->setLeft(n);
}