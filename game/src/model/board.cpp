//
// Created by razro on 2024-03-25.
//

#include "board.h"

//constructor
board::board(){
    for (auto &row: content) {
        for (auto &element: row) {
            element = '\0';
        }
    }
    initialState = true;
}

//getters
bool board::isInitialState() {
    return initialState;
}
void board::printContent() {
    for(auto& row : content){
        for(auto& element : row){
            std::cout << "|  " << element << "  ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "Initial state? " << this->isInitialState() << std::endl;
}
//setter
void board::setValue(int row, int column, char value) {
    content[row][column] = value;
    initialState = false;
}
//game related functions
// Return 1 if X won, -1 if O won, 0 otherwise,
char board::getWinner() {
    //      scores array to check with [row1, row2, row3, col1, col2, col3, diag1, diag2]
    int scores[8] = {0};
    int val;
//      coords of the forwards and backwards diagonal
    std::set<std::pair<int, int>> diag1 = {{0, 0}, {1, 1}, {2, 2}};
    std::set<std::pair<int, int>> diag2 = {{0, 2}, {1, 1}, {2, 0}};

//      iterate through each element
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            char element = content[row][column];
//                if the element is x +1 score, else -1
            if(element == 'X'){
                val = 1;
            }else if(element == 'O'){
                val = -1;
            }else{
                val = 0;
            }
//              add to relevant row and column
            scores[row]+= val;
            scores[column + 3] += val;

//              compute coord
            std::pair<int, int>coord(row, column);

//              check if coord is anywhere in the columns
            auto d1 = diag1.find(coord);
            if(d1 != diag1.end()){
                scores[6] += val;
            }
            auto d2 = diag2.find(coord);
            if(d2 != diag2.end()){
                scores[7] += val;
            }

        }
    }
    //      checking score values, +3 indicates an X win, -3 a O win, \0 if no one has won yet
    for(auto& score : scores){
        if(score >= 3){
            return 'X';
        }
        if(score <= -3){
            return 'O';
        }
    }
    return '\0';
}

// Returns true if board is terminal, false otherwise
bool board::isTerminal() {
    for(auto& row : content){
        for(auto& element : row){
//              If an empty slot exists, it is not terminal
            if(element == '\0'){
                return false;
            }
        }
    }
//      No empty slots means it is terminal state
    return true;
}

// Returns utility of a board: 1 if x wins, -1 if O wins, 0 otherwise
int board::getUtility() {
    int out = 0;
    char result  = this->getWinner();
    if(result == 'X'){
        out = 1;
    }else if(result == 'O') {
        out = -1;
    }
    return out;
}

// Calculates and returns the current player on the board
char board::getCurrentPlayer() {
    //        if board is in initial state, return X
    if(this->isInitialState()){
        return 'X';
    }else {
        int numx = 0;
        int numo = 0;
        for(auto& row : content){
            for(auto& element : row){
                if(element == 'X'){
                    numx++;
                }
                if(element == 'O'){
                    numo++;
                }
            }
        }
        char out = (numx > numo) ?  'O' : 'X';
        return out;
    }
}

// Returns board after making a move. Puts current player's value at the given coord.
board board::getResult(std::pair<int, int> move) {
    board currentboard = *this;
    int i = std::get<0>(move);
    int j = std::get<1>(move);
    char val = currentboard.getCurrentPlayer();

//  copy the board, make the move and return the value
    currentboard.setValue(i, j, val);

    return currentboard;
}

// Return a set of all possible actions of current board state
std::set<std::pair<int, int>> board::getActions() {
    std::set<std::pair<int, int>> moves;
//      for each row and column
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
//              check if there is available room
            if(content[i][j] == '\0'){
                moves.insert(std::make_pair(i,j));
            }
        }
    }
    return moves;
}

//Returns the optimal action of the current player on the board via minimax
std::pair<int, int> board::minimax() {
    board b = *this;
//      The move to be returned
    std::pair<int, int> action(-1, -1);

//      Terminal boards return -1 move(bad)
    if(b.isTerminal()){
        return action;
    }

//      Set of all possible actions
    std::set<std::pair<int, int>>moveSet = b.getActions();

//       Who is the current player playning as
    char player = b.getCurrentPlayer();

//      O is minimizing, X is maximizing
    if(player == 'X'){
        int max = -9999;
//            Check the value of each move
        for(auto& move : moveSet){
            int value = minValue(b.getResult(move));

            if(value > max){
                max = value;
                action = move;
            }
        }

    }else{
        int min = 9999;
        for(auto& move: moveSet){
            int value = maxValue(b.getResult(move));
            if(value < min){
                min = value;
                action = move;
            }
        }
    }

    return action;
}

int board::minValue(board b) {
    int v = 99999;

    if(b.isTerminal()){
        return b.getUtility();
    }

    for(auto& action : b.getActions()){
        v = std::min(v, maxValue(b.getResult(action)));
    }
    return v;
}

int board::maxValue(board b) {
    int v = -99999;
    if(b.isTerminal()){
        return b.getUtility();
    }
    for(auto& action : b.getActions()){
        v = std::max(v , minValue(b.getResult(action)));
    }

    return v;
}