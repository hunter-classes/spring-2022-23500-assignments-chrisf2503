#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "list.h"

stack* s = new stack();

TEST_CASE("Stack: part1"){
    CHECK(s->empty() == true);
    s->push(1);
    CHECK(s->top() == 1);
    s->push(2);
    CHECK(s->top() == 2);
    s->push(3);
    CHECK(s->top() == 3);
    s->push(4);
    CHECK(s->top() == 4);
    s->push(5);
    CHECK(s->top() == 5);
    CHECK(s->empty() == false);
    /*s->push(6);
    CHECK(s->top() == "The stack is full");*/
}
TEST_CASE("Stack: part2"){
    int num = 5;
    while(!s->empty()){
        CHECK(s->pop() == num);
        num--;
    }
    CHECK(s->empty() == true);
    
}