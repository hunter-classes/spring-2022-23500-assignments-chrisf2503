#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Person.h"
#include "Node.h"
#include "list.h"
#include "Dictionary.h"

Person *s1;
Person *s2;
Person *s3;
Person *s4;
Person *s5;
Person *s6;
Dictionary *dic;
TEST_CASE("Creating a student"){
    s1 = new Person("Chris", "Flores", 208577940); 
    CHECK(s1->get_name() == "Flores Chris");
    CHECK(s1->get_id() == 208577940);
    s2 = new Person("Kuya", "Lee", 209832049);
    CHECK(s2->get_name() == "Lee Kuya");
    CHECK(s2->get_id() == 209832049);
    s3 = new Person("David", "Garcia", 242018420);
    CHECK(s3->get_name() == "Garcia David");
    CHECK(s3->get_id() == 242018420);
}

TEST_CASE("Hash Index"){
    dic = new Dictionary();
    s4 = new Person("Stacy", "Cool", 294303840); 
    s5 = new Person("Vero", "Pena", 293484038);
    s6 = new Person("Sharlyn", "Rodriguez", 243590358);
    CHECK(dic->hashing(s1) == 2);
    CHECK(dic->hashing(s2) == 8);
    CHECK(dic->hashing(s3) == 2);
    CHECK(dic->hashing(s4) == 0);
    CHECK(dic->hashing(s5) == 9);
    CHECK(dic->hashing(s6) == 7);
}
TEST_CASE("inserting and finding student with their ID"){
    dic->insert(s1);
    dic->insert(s2);
    dic->insert(s3);
    dic->insert(s4);
    dic->insert(s5);
    dic->insert(s6);
    CHECK(dic->getPerson(208577950) == nullptr);
    CHECK(dic->getPerson(208577940) == s1);
    CHECK(dic->getPerson(209832049) == s2);
    CHECK(dic->getPerson(242018420) == s3);
    CHECK(dic->getPerson(294303840) == s4);
    CHECK(dic->getPerson(293484038) == s5);
    CHECK(dic->getPerson(243590358) == s6);
    
}//*/