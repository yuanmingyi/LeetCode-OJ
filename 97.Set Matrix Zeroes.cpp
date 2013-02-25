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
    void setZeroes(vector<vector<int> > &matrix) {
        int row = 0, col = 0;
        bool flag = true;
        while (row < matrix.size() && flag) {
            col = 0;
            while (col < matrix[row].size() && flag) {
                flag = matrix[row][col] != 0;                
                col++;  
            }
            row++;
        }
        if (flag) {
            return;
        }
        
        row--;
        col--;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                if (matrix[r][c] == 0) {
                    matrix[row][c] = 0;
                    matrix[r][col] = 0;
                }
            }
        }
        for (int r = 0; r < matrix.size(); r++) {
            if (r == row || matrix[r][col] != 0) {
                continue;
            }
            for (int c = 0; c < matrix[r].size(); c++) {
                matrix[r][c] = 0;
            }
        }
        for (int c = 0; c < matrix[row].size(); c++) {
            if (matrix[row][c] == 0) {
                for (int r = 0; r < matrix.size(); r++) {
                    matrix[r][c] = 0;
                }
            }
        }
        for (int c = 0; c < matrix[row].size(); c++) {
            matrix[row][c] = 0;
        }
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        vector<vector<int> > matrix;
        int d;
        char ch;
        istringstream iss(buff);
        iss >> ch;
        while (ch != ']') {
            vector<int> row;
            while (iss >> ch >> d) {
                row.push_back(d);
            }
            matrix.push_back(row);
            iss.clear();
            iss >> ch;
        }
        
        s.setZeroes(matrix);
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[r].size(); c++) {
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}