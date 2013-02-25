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
    vector<int> f;
public:
    Solution():f(1,1) {}
    
    int numTrees(int n) {
        int sz = f.size();
        if (n >= sz) {
            for (int i = sz; i <= n; i++) {
                int fi = 0;
                for (int j = 0; j < i; j++) {
                    fi += f[j] * f[i-j-1];
                    }
                f.push_back(fi);
            }
        }
        return f[n];
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        cout << s.numTrees(n) << endl;
    }
    return 0;
}