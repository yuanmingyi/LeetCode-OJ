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
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int r = 0; r <= rowIndex; r++) {
            for (int c = r - 1; c > 0; c--) {
                row[c] += row[c - 1];
            }
            row.push_back(1);
        }
        return row;
    }
};

int main(void) {
    Solution s;
    int row;
    while (cin >> row) {
        vector<int> ret = s.getRow(row);
        for (size_t i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";         
        }
        cout << endl;
    }
    return 0;
}