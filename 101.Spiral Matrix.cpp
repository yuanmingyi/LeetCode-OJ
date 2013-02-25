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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiral;
        
        int rows = matrix.size();
        if (rows == 0) {
            return spiral;
        }
        int cols = matrix[0].size();
        
        int s, lap = min(cols, rows);
        for (s = 0; s < lap/2; s++) {
            int r = s, c = s;
            while (c < cols - s - 1) {
                spiral.push_back(matrix[r][c]);
                c++;
            }
            while (r < rows - s - 1) {
                spiral.push_back(matrix[r][c]);
                r++;
            }
            while (c > s) {
                spiral.push_back(matrix[r][c]);
                c--;
            }
            while (r > s) {
                spiral.push_back(matrix[r][c]);
                r--;
            }
        }
        if (lap & 1) {
            int r = s;
            while (r < rows - s) {
                int c = s;
                while (c < cols - s) {
                    spiral.push_back(matrix[r][c]);
                    c++;
                }    
                r++;
            }            
        }
        return spiral;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        istringstream iss(buff);
        vector<vector<int> > mat;
        int d;
        char ch;
        iss >> ch;
        while (ch != ']') {
            vector<int> row;
            while (iss >> ch >> d) {
                row.push_back(d);
            }
            iss.clear();
            mat.push_back(row);
            iss >> ch;
        }
        vector<int> ret = s.spiralOrder(mat);
        for (size_t i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}