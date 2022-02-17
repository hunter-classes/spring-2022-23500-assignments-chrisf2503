#include <iostream>
#include "Nqueen.h"
#include <fstream>
#include <string>
#include <unistd.h>

int main(){
    Game g(8,8);
    std::cout << "[2J;\n";
    g.display();
    g.solve(7,9);
    g.display();
    return 0;
}