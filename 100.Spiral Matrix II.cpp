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
    vector<vector<int> > generateMatrix(int n) {        
        vector<vector<int> > mat;
        if (n == 0) return mat;
        mat = vector<vector<int> >(n, vector<int>(n, 0));        
        int i = 1, s;
        for (s = 0; s < n / 2; s++) {
            int r = s, c = s;
            while (c < n - s - 1) {
                mat[r][c] = i++;
                c++;
            }
            while (r < n - s - 1) {
                mat[r][c] = i++;
                r++;
            }
            while (c > s) {
                mat[r][c] = i++;
                c--;
            }
            while (r > s) {
                mat[r][c] = i++;
                r--;
            }
        }
        if (n & 1) {
            mat[s][s] = i;
        }
        return mat;
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        vector<vector<int> > mat = s.generateMatrix(n);
        for (size_t r = 0; r < mat.size(); r++) {
            for (size_t c = 0; c < mat[r].size(); c++) {
                cout << mat[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}