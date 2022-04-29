#pragma once
#include <vector>

class Queue{
    private:
        int q[5]; 
        int front;
        int indexF = 0;
        int back;
        int indexB = 0;
        int size;
        int limit = 5;
    public:
        Queue();
        Queue(int data);
        void enqueue(int data); //add an item to the back of the queue
        int sequeue(); // remove and return the item from the front of the queue
        int front_of_Queue(); // return but do not remove the item from the front of the queue
        bool is_empty();
        bool is_full();
};