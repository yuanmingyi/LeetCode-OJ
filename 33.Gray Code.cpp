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
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int maxv = 1 << n;
        vector<bool> mark(maxv, false);
        for (int i = 0, k = 0; i < maxv; i++) {
            ret.push_back(k);
            mark[k] = true;
            int x = 1;
            while (x < maxv && mark[k^x]) {
                x <<= 1;
            }
            k = k ^ x;
            mark[k] = true;
        }
        return ret;
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        vector<int> ret = s.grayCode(n);
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}