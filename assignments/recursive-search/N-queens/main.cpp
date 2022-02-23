#include <iostream>
#include "Nqueen.h"
#include <fstream>
#include <string>
#include <unistd.h>

int main(){
    Game g(50,50);
    std::cout << "[2J;\n";
    g.display();
    g.solve(29,24);
    g.display();
    return 0;
}