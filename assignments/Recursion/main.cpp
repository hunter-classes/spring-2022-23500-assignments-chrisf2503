#include <iostream>
#include <vector>

int mem[10000];
//using memoization
int stairs2(int n){
    if(n == 0){
        return 1;
    }
    if(mem[n] != 0){
        return mem[n];
    }
    else{
        int sum = 0;
        for(int i = 3; i >= 1; i--){
            int r = n - i;
            if(r >= 0){
                sum = sum + stairs2(r);
            }
        }
        mem[n] = sum;
        return sum;
    }
    
}
//oringinal way

int stairs(int n){
    if (n == 0){
        return 1;
    }

    int w = 0;
    for (int i = 3; i >= 1; i--){
        int r = n - i;
        if (r >= 0){
            w = w + stairs(r);
        }
    }
    return w;
}

int main(){
    for(int i = 0; i < 10000; i++){
        mem[i] = 0;
    }
    for(int i = 0; i < 1000; i++){
        std::cout << i << ": " << stairs2(i) << '\n';
    }

}