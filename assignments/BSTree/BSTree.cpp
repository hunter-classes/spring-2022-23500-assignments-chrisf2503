#include <iostream>
#include "BSTree.h"

BSTree::BSTree(){
    root = nullptr;
}

// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
    std::string a,b,c;
  
    if(n==nullptr){
      return "";
    } 
    else {
      /*
       *  pre-order traversal
     
        1. process the node
        2. recurse to left subtree
        3. recurse to right subtree

        a = std::to_string(n->getData());
        b =  traverse(n->getLeft());
        c =  traverse(n->getRight());
        * post-order traversal

        1. recurse to left subtree
        2. recurse to right subtree
        3. process the node
      
        a =  traverse(n->getLeft());
        b =  traverse(n->getRight());
        c = std::to_string(n->getData());
        */
        /*  
	      in-order traversal
	      1. recurse left subtree
	      2. process node
	      3. recurse right subtree
        */
        a =  traverse(n->getLeft());
        b = std::to_string(n->getData());
        c =  traverse(n->getRight());
        return a + ", " + b+ ", " + c;
    }
};

std::string BSTree::get_debug_String(){
    return traverse(root);
};

// we will always insert new nodes as leaves
void BSTree::insert(int value){

  // make a new node
  Node *newnode = new Node(value);
  
  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;

  
  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight(); 
    } else {
      p = p->getLeft();
    }
  }
  
  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }
  }
}
void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);
}

int BSTree::rsearch(int value){  
  return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p){
    if(p == nullptr){
        throw 1;
    }
    if(value == p->getData()){
        return p->getData();
    }
    if(value < p->getData()){
        return rsearch(value ,p->getLeft());
    }
    else{
        return rsearch(value ,p->getRight());
    }
}
/*Node* BSTree::findMaxNode(Node* current){
  Node* before;
  while(current->getRight() != nullptr){
    before = current;
    current = current->getRight();
  }
  before->setRight(nullptr);
  return current;   
}//*/

void BSTree::delNode(int val){
  if(root == nullptr){
    throw 1;
  }
  Node* walker = root;
  Node* before;
  //Node* after;
  //Node* bigNode;
  while(walker != nullptr){
    if(walker->getData() == val){
      break;
    }else if(walker->getData() < val){
      before = walker;
      walker = walker->getLeft();
    }else{
      before = walker;
      walker = walker->getRight();
    }
  }
  
  if(walker->getLeft() == nullptr){
    /*if(before->getRight() != nullptr){
      before->setRight(nullptr);
    }else{
      before->setLeft(nullptr);
    }//*/
  }//*/
  /*else if(walker->getRight() != nullptr){
    after = walker->getRight();
    if(before->getRight() != nullptr){
      before->setRight(after);
    }else{
      before->setLeft(after);
    }
  }
  else if(walker->getLeft() != nullptr){
    after = walker->getLeft();
    if(before->getRight() != nullptr){
      before->setRight(after);
    }else{
      before->setLeft(after);
    }
  }
  else{
    bigNode = findMaxNode(walker);
    if(before->getRight() != nullptr){
      before->setRight(bigNode);
    }else{
      before->setLeft(bigNode);
    }
    bigNode->setLeft(walker->getLeft());
    bigNode->setRight(walker->getRight());
  }
  //delete walker;*/
}