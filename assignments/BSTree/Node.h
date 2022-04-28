#pragma once

class Node{
    private:
        int data;
        Node* left;
        Node* right;

    public: 
        Node();
        Node(int data);
        Node(int data, Node* left, Node* right);
        int getData();
        Node* getLeft();
        Node* getRight();
        void setData(int data);
        void setLeft(Node* left);
        void setRight(Node* right);
};