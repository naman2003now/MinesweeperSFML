#pragma once

inline const int BOMB = 1;
inline const int EMPTY = 0;

class Game{
public:
    int board[10][10];
    int numbers[10][10];
    Game(const int size, const int numberOfBombs);
    ~Game();
};