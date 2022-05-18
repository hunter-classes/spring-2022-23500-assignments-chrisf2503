#include <iostream>
#include "Dictionary.h"
#include "list.h"
#include "Person.h"
#include "vector"

Dictionary::Dictionary(){
    for(int i = 0; i < 10; i++){
        hash.push_back(nullptr);
        hash[i] = new List();
    }
}
Dictionary::~Dictionary(){
  for(int i = 0; i < 20; i++){
    delete hash[i];
    hash[i] = nullptr;
  }
}
int Dictionary::hashing(Person *p){
    return p->get_name().length() % hash.size();
}
void Dictionary::insert(Person *p){
    hash[hashing(p)]->insert(p);
}
Person* Dictionary::getPerson(int ID){
    List *l;
    int length = 0;
    for(int i = 0; i < hash.size(); i++){
        l = hash[i];
        while(length != l->length()){
            if(l->get(length)->get_id() == ID){
                return l->get(length);
            }
            length++;
        }
        length = 0;
    }
    return nullptr;
}
void Dictionary::getAllKeys(){
    List *l;
    int length = 0;
    for(int i = 0; i < hash.size(); i++){
        l = hash[i];
        while(length != l->length()){
            std::cout << l->get(length)->get_name() << '\n';
            length++;
        }
        length = 0;
    }
}