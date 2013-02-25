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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > sol;
        vector<int> row;        
        for (int r = 0; r < numRows; r++) {
            for (int c = r - 1; c > 0; c--) {
                row[c] += row[c-1];
            }
            row.push_back(1);            
            sol.push_back(row);
        }
        
        return sol;
    }
};

int main(void) {
    Solution s;
    int nrow;
    while (cin >> nrow) {
        vector<vector<int> > ret = s.generate(nrow);
        for (size_t i = 0; i < ret.size(); i++) {
            for (size_t j = 0; j < ret[i].size(); j++) {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}