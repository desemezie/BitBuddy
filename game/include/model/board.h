//
// Created by razro on 2024-03-25.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include <utility>
#include <set>
#include <iostream>

class board {
private:
    char content[3][3];
    bool initialState;
//  minimax helpers
    int maxValue(board b);
    int minValue(board b);
public:
    board();
//  getters
    bool isInitialState();
    void printContent();
//  setters
    void setValue(int row, int column, char value);

//  game specific
    char getWinner();
    bool isTerminal();
    int getUtility();
    char getCurrentPlayer();
    board getResult(std::pair<int, int> move);
    std::set<std::pair<int, int>> getActions();
    std::pair<int, int> minimax();



};


#endif //TICTACTOE_BOARD_H
