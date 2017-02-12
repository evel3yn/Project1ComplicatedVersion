//Name: Simin Wen
//VUnetid: wens3
//email address: simin.wen@vanderbilt.edu

#include <iostream>
#include<fstream>
#include <deque>
#include "Sudoku.h"
#include <algorithm>

Sudoku::Sudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            //initialize
            sdk[i][j] = 0;
        }
    }
}

void Sudoku::loadFromFile(std::string filename) {
    std::ifstream in(filename);
    if (in) {
        //if open it successfully
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                //read it in
                in >> sdk[i][j];
            }
        }
    }

}

bool Sudoku::solve() {
    //use the backtrace algorithm
    bool suc = backtrace(0);
    //return whether success or not
    return suc;
}

bool Sudoku::isPlace(int count) {
    //whether can be placed here
    int row = count / 9;
    int col = count % 9;
    int i;
    //same row
    for (i = 0; i < 9; ++i) {
        if (sdk[row][i] == sdk[row][col] && i != col) {
            return false;
        }
    }
    //same column
    for (i = 0; i < 9; ++i) {
        if (sdk[i][col] == sdk[row][col] && i != row) {
            return false;
        }
    }
    //same block
    int tempR = row / 3 * 3;
    int tempC = col / 3 * 3;
    for (i = tempR; i < tempR + 3; ++i) {
        for (int j = tempC; j < tempC + 3; ++j) {
            if (sdk[i][j] == sdk[row][col] && i != row && j != col) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::backtrace(int count) {
    //flag==1: already success
    int flag = 0;
    if (count == 81) {
        return true;
    }
    //row
    int row = count / 9;
    //column
    int col = count % 9;
    //if this element doesn't have value
    if (sdk[row][col] == 0) {
        for (int i = 1; i <= 9; ++i) {
            //set a value for it
            sdk[row][col] = i;
            if (isPlace(count)) {
                //it can be place here
                //analyze the next element
                flag = backtrace(count + 1);
                //if it already success
                //stop loop, just return
                if (flag) return true;
            }
        }
        //if there is no appropriate value
        //traceback
        //set the element value as zero
        sdk[row][col] = 0;
        return false;
    } else {
        //if this element already has value
        //analyze the next element
        flag = backtrace(count + 1);
        //return the flag
        return (bool) flag;
    }
}

void Sudoku::print() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            //print
            std::cout << sdk[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Sudoku::equals(const Sudoku &other) const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            //compare
            if (!sdk[i][j] == other.sdk[i][j])
                return false;
        }

    }
    return true;
}
