#pragma once
#include "list.h"
#include "Person.h"
#include <vector>

class Dictionary{
    private:
        std::vector<List*> hash;
        int maxSize = 10;
    public:
        Dictionary();
        ~Dictionary();
        int hashing(Person *p);
        void insert(Person *p);
        Person* getPerson(int ID);
        void getAllKeys();
};