#include <iostream>
#include "Nqueen.h"

int main(){
    Game g(4,4);
    //g.display();
    g.solve(0,2);
    return 0;
}