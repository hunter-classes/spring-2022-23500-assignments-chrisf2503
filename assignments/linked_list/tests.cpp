#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Olist.h"
#include "Node.h"

Olist *list = new Olist();

TEST_CASE("Creating a list/inserting"){
    CHECK(list->toString() == "nullptr");
    list->insert(1);
    list->insert(2);
    list->insert(-1);
    list->insert(-2);
    list->insert(0);
    list->insert(10);
    list->insert(5);
    CHECK(list->toString() == "-2 ---> -1 ---> 0 ---> 1 ---> 2 ---> 5 ---> 10 ---> nullptr");
}
TEST_CASE("Getting val/containing val"){
    int vals[] = {-2,-1,0,1,2,5,10};
    for(int i = 0; i < 7; i++){
        CHECK(list->get(i) == vals[i]);
    }
    CHECK(list->contain(-1) == true);
    CHECK(list->contain(-9) == false);
    CHECK(list->contain(10) == true);
    CHECK(list->contain(-10) == false);
}
TEST_CASE("Deleting a Node/Revserse/deleting the whole list"){
    list->remove(5);
    list->remove(0);
    CHECK(list->toString() == "-1 ---> 0 ---> 1 ---> 2 ---> 10 ---> nullptr");
    list->reverse();
    CHECK(list->toString() == "10 ---> 2 ---> 1 ---> 0 ---> -1 ---> nullptr");
    list->~Olist();
    CHECK("nullptr");
}