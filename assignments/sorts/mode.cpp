#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
int count(std::vector<int> v, int value);
int largest(std::vector<int> v);
int mode(std::vector<int> v);
void printVec(std::vector<int> v);
int main(){
    int size = 30000; // default vector size
    //int size = 10000; // default vector size
    int max_val = 100; // default max value for entries
    srand(time(NULL));
    std::vector<int> a(size);
    int i;
    for(i=0;i<size;i++){
        a[i] = rand()%max_val;    
    }
    printVec(a);
    std::cout << mode(a) << '\n';
    return 0;
}

int count(std::vector<int> v, int value){
    int co = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v[i] == value){
            co++;
        }
    }
    return co;
}

int largest(std::vector<int> v){
    int large = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] > large){
            large = v[i]; 
        }
    }
    return large;
}

int mode(std::vector<int> v){
    int bigCount = 0;
    int currentCount = 0;
    int num = v[0];
    int next = 1;
    for(int i = 0; i < v.size(); i++){
        if(num == v[i]){
            currentCount++;
        }
        if(i == v.size() - 1 && v[i] == num){
            i = v.size();
        } 
        else if(i == v.size() - 1){
            i = -1;
            if(bigCount <= currentCount){
                bigCount = num;
                currentCount = 0;
            }
            next++;
            num = v[next];
        }
    }
    return bigCount;
}

void printVec(std::vector<int> v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}