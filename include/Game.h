#pragma once

inline const int BOMB = 1;
inline const int EMPTY = 0;

class Game{
public:
    int board[1000][1000];
    int numbers[1000][1000];
    void Click(int x, int y);
    void Flagged(int x, int y);
    Game(const int size, const int numberOfBombs);
    ~Game();
};