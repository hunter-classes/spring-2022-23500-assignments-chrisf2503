#include <iostream>
#include "list.h"
#include "stack.h"

stack::stack(){
    head = new List();
    size = 0;
}
void stack::push(int val){
    head->insert(val);
    size++;
}
int stack::pop(){
    int val = head->get(0);
    head->remove(0);
    size--;
    return val;
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
