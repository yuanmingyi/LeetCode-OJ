#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > solutions;
        
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        vector<int> st;
        int r = 0, c = 0;
        
        while (!st.empty() || c < n) {
            while (r < n && c < n) {
                if (col[c] || diag1[r+c] || diag2[r-c+n-1]) {
                    c++;
                } else {
                    st.push_back(c);
                    col[c] = true;
                    diag1[r+c] = true;
                    diag2[r-c+n-1] = true;
                    r++;
                    c = 0;
                }
            }
            if (r >= n) {
                vector<string> solution;
                for (int i = 0; i < st.size(); i++) {
                    vector<char> line(n+1, '.');
                    line[st[i]] = 'Q';
                    line[n] = 0;
                    solution.push_back(line.data());
                }
                solutions.push_back(solution);                
            }
            c = st.back();
            st.pop_back();
            r--;
            col[c] = false;
            diag1[r+c] = false;
            diag2[r-c+n-1] = false;
            c++;
        }
        
        return solutions;
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        vector<vector<string> > sol = s.solveNQueens(n);
        for (size_t i = 0; i < sol.size(); i++) {
            for (size_t j = 0; j < sol[i].size(); j++) {
                cout << sol[i][j] << endl;
            }
            cout << endl;
        }
    }
    return 0;
}