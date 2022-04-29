#include <iostream>
#include "Queues.h"
#include <vector>

Queue::Queue(){
    front = 0;
    back = 0;
    size = 0;
}

Queue::Queue(int data){
    front = data;
    back = data;
    q[indexF%limit] = data;
    size = 1;
    indexF++;
}

void Queue::enqueue(int data){
    try{
        if(size == limit){
            throw std::out_of_range("full");
        }
        if(size == 0){
            front = data;
            back = data;
            q[indexB] = data;
        }
        else if(size != limit){
            q[indexB] = data;
            back = data;
        }
        size++;
        indexB++;
        indexB = indexB%limit;
    }
    catch(...){
        std::cout << "Queue is full'\n";
    }
}
int Queue::sequeue(){
    int val = 0;
    try{
        if(size == 0){
            throw std::out_of_range("empty");
        }
        val = front;
        if(indexB == indexF){
            front = 0;
            back = 0;
            q[indexF] = 0;
        }
        else{
            val = q[indexF];
            q[indexF] = 0; 
        }
        size--;
        indexF++;
        indexF = indexF%limit;
        front = q[indexF];

    }catch(...){
        std::cout << "Already empty\n";
    }
    return val;
}//*/
int Queue::front_of_Queue(){
    return front;
}

bool Queue::is_empty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::is_full(){
    if(size == limit){
        return true;
    }
    else{
        return false;
    }
}