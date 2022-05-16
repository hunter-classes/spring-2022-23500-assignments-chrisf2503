#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"
#include "Node.h"

BSTree *tree1 = new BSTree();
BSTree *tree2 = new BSTree(); 
TEST_CASE("search"){
    tree1->setup();
    CHECK(10 == tree1->rsearch(10));
    CHECK(15 == tree1->rsearch(15));
    CHECK(2 == tree1->rsearch(2));
    CHECK_THROWS(tree1->rsearch(34));
    CHECK_THROWS(tree1->rsearch(25));
    tree1->insert(1);
    CHECK(1 == tree1->rsearch(1));
    //CHECK();
}
TEST_CASE("Deleting a node"){
    tree1->delNode(3);
    tree1->delNode(5);
    tree1->delNode(20);
    CHECK_THROWS(tree1->rsearch(3));
    CHECK_THROWS(tree1->rsearch(5));
    CHECK_THROWS(tree1->rsearch(20));
    CHECK(8 == tree1->rsearch(8));
    CHECK(1 == tree1->rsearch(1));
    CHECK(15 == tree1->rsearch(15));
}
TEST_CASE("sums"){
    tree2->setup();
    CHECK(10 == tree2->sums(1));
    CHECK(25 == tree2->sums(2));
    CHECK(56 == tree2->sums(3));
    CHECK(9 == tree2->sums(4));
}
TEST_CASE("height"){
    CHECK(4 == tree2->getHeight());
    CHECK(4 == tree1->getHeight());
    //tree1->delNode(8);
    tree1->delNode(7);
    tree1->delNode(2);
    CHECK(3 == tree1->getHeight());
    tree2->insert(1);
    CHECK(5 == tree2->getHeight());
    tree2->insert(-7);
    CHECK(6 == tree2->getHeight());
}
TEST_CASE("If cousins"){
    CHECK(tree1->cousin(8, 30));
    CHECK(tree1->cousin(1, 15));
    CHECK(!tree1->cousin(10, 30));
    CHECK(tree2->cousin(3, 30));
    CHECK(!tree2->cousin(2, 20));
    CHECK(!tree2->cousin(-7, 10));
    CHECK(tree2->cousin(2, 7));
}