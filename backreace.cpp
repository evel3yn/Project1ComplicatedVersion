//
// Created by SiminWen on 2/4/2017.
//

#include <iostream>
#include <algorithm>
#include<fstream>

using namespace std;
int map[9][9];

bool isPlace(int count) {
    int row = count / 9;
    int col = count % 9;
    int j;
    //同一行
    for (j = 0; j < 9; ++j) {
        if (map[row][j] == map[row][col] && j != col) {
            return false;
        }
    }
    //同一列
    for (j = 0; j < 9; ++j) {
        if (map[j][col] == map[row][col] && j != row) {
            return false;
        }
    }
    //同一小格
    int tempRow = row / 3 * 3;
    int tempCol = col / 3 * 3;
    for (j = tempRow; j < tempRow + 3; ++j) {
        for (int k = tempCol; k < tempCol + 3; ++k) {
            if (map[j][k] == map[row][col] && j != row && k != col) {
                return false;
            }
        }
    }
    return true;
}

bool backtrace(int count) {
    int flag = 0;
    if (count == 81) {
        cout << "result" << endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    int row = count / 9;
    int col = count % 9;
    if (map[row][col] == 0) {
        for (int i = 1; i <= 9; ++i) {
            map[row][col] = i;//赋值
            if (isPlace(count)) {//可以放
                flag = backtrace(count + 1);//进入下一层
                if (flag)
                    return true;
            }
        }
        map[row][col] = 0;//回溯
        return (bool) flag;
    } else {
        flag = backtrace(count + 1);
        return (bool) flag;
    }
}

int main() {
    std::ifstream in("D:\\Project1\\Sudok\\sudoku-test1.txt");
    if (in) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                in >> map[i][j];
            }
        }
    }
    bool ddd = backtrace(0);
    if (!ddd) {
        cout << "false";
    } else {
        cout << "true";
    }
    return 0;
}