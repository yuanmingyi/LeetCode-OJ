#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:     
    int numState(int state) {
        int num = 0;
        while (state) {
            state &= state - 1;
            num++;
        }
        return num;
    }
    
    bool solveRecursive(vector<vector<char> >& board) {
        int row, col, block;
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> blocks(9, 0);
        
        for (int i = 0; i < 81; i++) {
            row = i / 9;
            col = i % 9;
            block = (row/3)*3 + col/3;
            char c = board[row][col];
            if (c != '.') {
                int x = 1 << c - '1';
                rows[row] |= x;
                cols[col] |= x;
                blocks[block] |= x;
            }
        }
        
        int minNumState = 0;
        int minPos = -1;
        int minState = 0;
        
        for (int i = 0; i < 81; i++) {
            row = i / 9;
            col = i % 9;
            block = (row/3)*3 + col/3;
            char c = board[row][col];
            if (c == '.') {
                int state = ~(rows[row] | cols[col] | blocks[block]) & ((1 << 9) - 1);
                int num = numState(state);
                if (minPos < 0 || num < minNumState) {
                    minNumState = num;
                    minPos = i;
                    minState = state;
                }
                if (minNumState == 1) {
                    break;
                }
            }
        }
        
        if (minPos < 0) {
            return true;
        }       
        
        if (minNumState < 1) {
            return false;
        }
        
        row = minPos / 9;
        col = minPos % 9;
        int num = 0;
        while (num < 9) {            
            if (minState & 1) {
                board[row][col] = num + '1';
                if (solveRecursive(board)) {
                    return true;
                }
            } 
            num++;            
            minState >>= 1;            
        }
        board[row][col] = '.';
 
        return false;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        solveRecursive(board);
    }
};

int main(void) {
    return 0;
}