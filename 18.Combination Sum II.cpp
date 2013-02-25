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
    void comb(const vector<int> &num, int s, const vector<string> &g, int target, const vector<int> &pre, vector<vector<int> > &result) {
        if (target == 0) {
            result.push_back(pre);
        } else {
            int last = 0;
            for (int i = s; i >= 0; i--) {
                if (g[target][i] == '1' && num[i] != last) {
                    vector<int> preseq = pre;
                    preseq.push_back(num[i]);
                    comb(num, i - 1, g, target - num[i], preseq, result);
                    last = num[i];
                }
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end(), greater<int>());
        
        vector<bool> f(target+1, false);
        vector<string> g(target+1);
        f[0] = true;
        for (int i = 0; i < num.size(); i++) {
            for (int j = target; j > 0; j--) {
                if (j >= num[i] && f[j - num[i]]) {
                    f[j] = true;
                    g[j].push_back('1');
                } else {
                    g[j].push_back('0');
                }
            }
        }
        
        vector<vector<int> > ret;
        comb(num, num.size() - 1, g, target, vector<int>(), ret);
        return ret;
    }
};

int main(void) {
    Solution s;
    char ch;
    int n = 0;
    while (cin >> ch) {
        if (ch == '[') {
            vector<int> num;
            while (ch != ']') {
                int d;
                if (scanf("%d", &d)) {
                    num.push_back(d);
                }
                cin >> ch;
            }
            int target;
            cin >> ch >> target;
            vector<vector<int> > result = s.combinationSum2(num, target);
            
            cout << "case " << ++n << endl;
            for (int i = 0; i < result.size(); i++) {
                for (int j = 0; j < result[i].size(); j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}