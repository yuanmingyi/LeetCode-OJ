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
    int minPathSum(vector<vector<int> > &grid) {

        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }            
        
        int maxlen = min(m, n);
        vector<int> s1(maxlen, 0), s2(maxlen, 0);
        
        for (int i = 0; i < m + n - 1; i++) {
            for (int c = max(0, i - m + 1), k = 0, l = 0; c <= min(i, n - 1); c++) {
                int r = i - c;
                if (r == 0 || c == 0) {
                    s2[k] = s1[l] + grid[r][c];
                } else {
                    s2[k] = min(s1[l], s1[l+1]) + grid[r][c];
                    l++;
                } 
                k++;
            }
            s1 = s2;
        }
        
        return s1[0];
    }
};

int main(void) {
    return 0;
}