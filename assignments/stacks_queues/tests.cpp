#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "list.h"
#include "Queues.h"
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
Queue *q = new Queue();
TEST_CASE("Queue: part 1"){
    CHECK(q->is_empty());
    q->enqueue(1);
    CHECK(q->front_of_Queue() == 1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    CHECK(q->is_full());
}
TEST_CASE("Queue: part2 "){
   CHECK(q->sequeue() == 1);
   CHECK(q->front_of_Queue() == 2);
   CHECK(q->sequeue() == 2);
   CHECK(q->front_of_Queue() == 3);
   CHECK(q->sequeue() == 3);
   CHECK(q->front_of_Queue() == 4);
   CHECK(q->sequeue() == 4);
   CHECK(q->front_of_Queue() == 5);
   CHECK(q->sequeue() == 5);
   //CHECK(q->front_of_Queue() == 6);
   q->enqueue(6);
   q->enqueue(7);
   CHECK(q->front_of_Queue() == 6);
   CHECK(q->sequeue() == 6); 
   CHECK(q->front_of_Queue() == 7);
   CHECK(q->sequeue() == 7);
   CHECK(q->is_empty());
}//*/