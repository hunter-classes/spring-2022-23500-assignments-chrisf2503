#include <iostream>
#include "stack.h"

int main(){
    std::cout << "Stack Testing:";
    stack* s = new stack();
    if(s->empty()){
        std::cout << "The stack is currently empty\n";
    }
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);//This will catch a out of Range error because the stack is full
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
    /*The next pop will give us an out of range error*/
    s->pop();
    
    return 0;
}