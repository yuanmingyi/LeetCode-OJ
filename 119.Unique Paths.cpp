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
    int uniquePaths(int m, int n) {
        double x = 1;
        if (m < n) swap(m, n);
        for (int i = 1; i < n; i++) {
            x = x * (m+i-1) / i;
        }
        
        return (x - (int)x >= 0.5 ? (int)x + 1: (int)x);
    }
};

int main(void) {
    Solution s;
    int m, n;
    while (cin >> m >> n) {
        cout << s.uniquePaths(m, n) << endl;
    }
    return 0;
}