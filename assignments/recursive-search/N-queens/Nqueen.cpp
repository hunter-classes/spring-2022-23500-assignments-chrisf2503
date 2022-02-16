#include <iostream>
#include "Nqueen.h"

Game::Game(int rSize, int cSize){
    board = new char*[rSize];
    sizeRow = rSize;
    sizeCol = cSize;
    for(int i = 0; i < rSize; i++){
        board[i] = new char[cSize];
    }
    for(int i = 0; i < rSize; i++){
        for(int j = 0; j < cSize; j++){
            board[i][j] = '.';
        }
    }
}

void Game::display(){
    for(int i = 0; i < sizeRow; i++){
        for(int j = 0; j < sizeCol; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void Game::solve(int row, int col){
    for(int i = 0; i < sizeRow; i++){
        for(int j = 0; j < sizeCol; j++){
            if(board[i][j] == queen){
                //This represent the y intercepts for the current queen
                int yinter1 = i + j;
                int yinter2 = i - j;
                //This represent the y intercepts for the queen we want to place
                int Yinter1 = row + col;
                int Yinter2 = row - col;
                if(i == row){
                    return;
                }
                if(j == col){
                    return;
                }
                if(yinter1 == Yinter1 || yinter2 == Yinter2){
                    return;
                }
            }
        }
    }
    board[row][col] = queen;
    display();
    std::cout << '\n';
    for(int i = 0; i < sizeRow; i++){
        for(int j = 0 ; j < sizeCol; j++){
            solve(i, j);
        }
    }

}