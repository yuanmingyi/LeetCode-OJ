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
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        
        vector<int> st;
        int count = 0;
        int r = 0, c = 0;
        while (!st.empty() || c < n) {
            while (r < n && c < n) {
                if (col[c] || diag1[r+c] || diag2[r-c+n-1]) c++;
                else {
                    st.push_back(c);
                    col[c] = true;
                    diag1[r+c] = true;
                    diag2[r-c+n-1] = true;
                    r++; 
                    c = 0;    
                }
            }
            if (r >= n) {
                count++;
            }
            c = st.back();
            r--;
            st.pop_back();
            col[c] = false;
            diag1[r+c] = false;
            diag2[r-c+n-1] = false;
            c++;                        
        }
        
        return count;
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        cout << s.totalNQueens(n) << endl;
    }
    return 0;
}