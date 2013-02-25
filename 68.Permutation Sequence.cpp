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
    int f[10];
public:
    Solution() {
        f[0] = 1;
        for (int i = 1; i < 10; i++) {
            f[i] = f[i-1]*i;
        }
    }
    
    string getPermutation(int n, int k) {
        string ret;
        vector<bool> used(n+1, false);
        while (n-- > 0) {
            int d = (k - 1) / f[n] + 1;
            int x = 0;
            while (d > 0) {
                if (!used[++x]) {
                    d--;
                }     
            }
            used[x] = true;
            ret.push_back(x+'0');
            k = (k - 1) % f[n] + 1;            
        }
        return ret;
    }
};

int main(void) {
    Solution s;
    int n, k;
    char c;
    while (cin >> n >> c >> k) {
        string ret = s.getPermutation(n, k);
        cout << ret << endl;
    }
    return 0;
}