#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
    std::vector<int> merged;
    int l = 0, r = 0;
    while(l != left.size() && r != right.size()){
        if(left[l] > right[r]){
            merged.push_back(right[r]);
            r++;
        }
        else{
            merged.push_back(left[l]);
            l++;
        }
    }
    while(l != left.size()){
        merged.push_back(left[l]);
        l++;
    }
    while(r != right.size()){
        merged.push_back(right[r]);
        r++;
    }
    return merged;
}

std::vector<int> msort(std::vector<int> list){
    if(list.size() <= 1){
        return list;
    }
    int mid = list.size()/2;
    std::vector<int> l1,l2;
    for(int i = 0; i < list.size(); i++){
        if(i < mid){
            l1.push_back(list[i]);
        }
        else{
            l2.push_back(list[i]);
        }
    }
    l1 = msort(l1);
    l2 = msort(l2);
    list = merge(l1,l2);
    return list;
}
void printVec(std::vector<int> v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}
int main(){
    int size = 30; // default vector size
    //int size = 10000; // default vector size
    int max_val = 100; // default max value for entries
    srand(time(NULL));
    std::vector<int> a(size);
    int i;
    for(i=0;i<size;i++){
        a[i] = rand()%max_val;    
    }
    printVec(a);
    std::vector<int> b = msort(a);
    printVec(b);
    return 0;
}