#include <iostream>
#include "stack.h"

int main(){
    stack* s = new stack();
    if(s->empty()){
        std::cout << "The stack is currently empty\n";
    }
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->printStack();
    std::cout << "The current val of the top is: " << s->top() << '\n';
    int del = s->pop();
    s->printStack();
    std::cout << "new top is " << s->top() << '\n';
    
    while(!s->empty()){
        del = s->pop();
        std::cout << "Val deleted: " << del << "\n";
        if(!s->empty()){
            std::cout << "new top is: " << s->top() << '\n';
        }
        else{
            std::cout << "Stack is currently empty\n"; 
        }
    }
    s->printStack();
    //The next pop will give us an out of range error 
    //del = s->pop();
    return 0;
}