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
    void comb(int n, int k, int s, const vector<int>& pre, vector<vector<int> >& result) {
        if (k <= 0) {
            result.push_back(pre);
        } else {
            for (; s <= n; s++) {
                vector<int> preseq = pre;
                preseq.push_back(s);
                comb(n, k - 1, s + 1, preseq, result);
            }
        }        
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        vector<vector<int> > result;
        comb(n, k, 1, vector<int>(), result);
        return result;
    }
};

int main(void) {
    Solution s;
    int n, k, count = 0;
    while (scanf("%d,%d", &n, &k) == 2) {
        vector<vector<int> > ret = s.combine(n, k);
        cout << "case " << ++count << endl;
        for (int i = 0; i < ret.size(); i++) {
            for (int j = 0; j < ret[i].size(); j++) {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}