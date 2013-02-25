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
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if (rows < 1) return false;
        int cols = matrix[0].size();
        if (cols < 1) return false;
        
        int start = 0, end = rows;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (matrix[middle][0] <= target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        if (start < 1) return false;
        int row = start - 1;
        start = 0;
        end = cols;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (matrix[row][middle] < target) {
                start = middle + 1;
            } else if (matrix[row][middle] > target) {
                end = middle;
            } else {
                return true;
            }
        }
        
        return false;
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
            iss.clear();
            matrix.push_back(row);
            iss >> ch;            
        }
        iss >> ch >> d;
        cout << (s.searchMatrix(matrix, d) ? "true" : "false") << endl;
    }
    return 0;
}