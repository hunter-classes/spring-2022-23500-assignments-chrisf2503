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
    return 0;
}