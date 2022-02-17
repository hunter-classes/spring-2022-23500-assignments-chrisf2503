#pragma once

class Game{
    public:
    Game(int rSize, int cSize);
    void display(); 
    void solve(int row, int col);

    private: 
    char** board;
    char queen = 'Q';
    int sizeRow = 0;
    int sizeCol = 0;
};