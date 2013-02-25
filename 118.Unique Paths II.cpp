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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {        
        int m = obstacleGrid.size();
        int n = m ? obstacleGrid[0].size() : 0;
        vector<int> paths(n+1,0);
        paths[0] = 1;
        for (int i = 0; i < m + n - 1; i++) {
            for (int r = max(0, i-n+1), c = i - r; r < m && c >= 0; r++, c--) {                
                if (obstacleGrid[r][c]) {
                    paths[c] = 0;
                } else if (c > 0) {
                    paths[c] += paths[c-1];
                }
            }
        }
        return n > 0 ? paths[n-1] : 0;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        vector<vector<int> > board;
        istringstream iss(buff);
        int d;
        char ch;
        while (iss >> ch && ch != ']') {
            vector<int> row;
            while (iss >> ch >> d) {
                row.push_back(d);
            }
            board.push_back(row);
            iss.clear();
        }
        cout << s.uniquePathsWithObstacles(board) << endl;        
    }
    
    return 0;
}