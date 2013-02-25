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
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows = triangle.size();
        int minTotal = 0;
        vector<int> minSum(rows, 0);        
        for (int r = 0; r < rows; r++) {            
            for (int c = r; c > 0; c--) {
                minSum[c] = triangle[r][c] + (c < r ? min(minSum[c], minSum[c-1]) : minSum[c-1]);
            }
            minSum[0] += triangle[r][0];
        }
        for (int r = 0; r < rows; r++) {
            if (r == 0 || minSum[r] < minTotal) {
                minTotal = minSum[r];
            }
        }
        return minTotal;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        istringstream iss(buff);
        vector<vector<int> > triangle;
        int d;
        char ch;
        while (iss >> ch && ch != ']') {
            vector<int> row;
            while (iss >> ch >> d) {
                row.push_back(d);
            }
            triangle.push_back(row);
            iss.clear();
        }
        cout << s.minimumTotal(triangle) << endl;
    }
    
    return 0;
}