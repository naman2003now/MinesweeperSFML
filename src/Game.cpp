#include "Game.h"
#include <random>
#include <time.h>
#include <iostream>

Game::Game(const int size, const int numberOfBombs){
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            numbers[i][j] = 0;
        }
    }
    

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!(rand()%numberOfBombs)){
                board[i][j] = BOMB;
                std::cout << "B ";
            }else{
                board[i][j] = EMPTY;
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!board[i][j]){
            if(i != 0){
                numbers[i][j] += board[i - 1][j];
            }
            if(i + 1 < size){
                numbers[i][j] += board[i + 1][j];
            }
            if(j != 0){
                numbers[i][j] += board[i][j - 1];
            }
            if(j + 1 < size){
                numbers[i][j] += board[i][j + 1];
            }
            if(i != 0 && j != 0){
                numbers[i][j] += board[i - 1][j - 1];
            }
            if(i + 1 < size && j + 1 < size){
                numbers[i][j] += board[i + 1][j + 1];
            }
            if(i != 0 && j + 1 < size){
                numbers[i][j] += board[i - 1][j + 1];
            }
            if(i + 1 < size && j != 0){
                numbers[i][j] += board[i + 1][j - 1];
            }
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int number = numbers[i][j];
            if(number){
                std::cout << number  << " ";
            }
            else{
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

Game::~Game(){

}