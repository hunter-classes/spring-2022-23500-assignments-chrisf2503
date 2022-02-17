#include <iostream>
#include "Nqueen.h"
#include <fstream>
#include <string>
#include <unistd.h>

int main(){
    Game g(4,4);
    std::cout << "[2J;\n";
    g.display();
    g.solve(0,3);
    g.display();
    return 0;
}