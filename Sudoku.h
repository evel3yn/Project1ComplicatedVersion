//
// Created by SiminWen on 2/2/2017.
//

#ifndef SUDOK_SUDOKU_H
#define SUDOK_SUDOKU_H

#include <vector>
#include <deque>
#include <array>

class Sudoku {
private:
    int sdk[9][9];
public:
    Sudoku();

    void loadFromFile(std::string filename);

    bool solve();

    void print() const;

    bool isPlace(int count);

    bool backtrace(int count);

    bool equals(const Sudoku &other) const;
};

#endif //SUDOK_SUDOKU_H
