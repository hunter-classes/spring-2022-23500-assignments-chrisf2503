#pragma once
#include "list.h"
class stack{
    private:
        List* head;
        int size;
        int limitOfStack;
    public:
        stack();
        void push(int val);//put a limit and use try and catch
        int pop();//put a try or catch
        int top();
        void printStack();
        bool empty();
};