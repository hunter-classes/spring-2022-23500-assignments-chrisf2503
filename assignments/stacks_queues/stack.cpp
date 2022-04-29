#include <iostream>
#include "list.h"
#include "stack.h"

stack::stack(){
    head = new List();
    size = 0;
    limitOfStack = 5;
}
void stack::push(int val){
    try{
        if(size != limitOfStack){
            head->insert(val);
            size++;
        }
        else{
            throw std::out_of_range("full");
        }
    }catch(...){
        std::cout << "The stack is full" << '\n'; 
    }
}
int stack::pop(){
    try{
        if(size != 0){
            int val = head->get(0);
            head->remove(0);
            size--;
            return val;
        }
        else{
            throw std::out_of_range("Empty");
            
        }
    }catch(...){
        std::cout << "Stack is already empty";
    }
    return 0;
}
int stack::top(){
    return head->get(0);
}
void stack::printStack(){
    List* walker = head;
    int index = 0;
    while(index != size){
        std::cout << "[ " << walker->get(index) << " ]\n";
        index++;
    }
}
bool stack::empty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}
