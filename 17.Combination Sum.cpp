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
    bool getbit(int v, int b) {
        return (v & 1 << b);
    }
    void setbit(int &v, int b) {
        v |= 1 << b;
    }
    void unsetbit(int &v, int b) {
        v &= ~(1 << b);
    }
    
public:
    void comb(const vector<int> &cands, int s, const vector<int> &f, int target, const vector<int>& preseq, vector<vector<int> > &result) {
        vector<vector<int> > ret;
        if (target == 0) {
            result.push_back(preseq);
            return;
        }
        for (int i = s; i >= 0; i--) {
            if (getbit(f[target], i)) {
                vector<int> pre = preseq;
                pre.push_back(cands[i]);
                comb(cands, i, f, target - cands[i], pre, result);
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int> > ret;
        vector<int> f(target+1, 0);
        f[0] = 1;
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= candidates[i] && f[j - candidates[i]]) {
                    setbit(f[j], i);
                } else {
                    unsetbit(f[j], i);
                }
            }            
        }
                
        comb(candidates, candidates.size() - 1, f, target, vector<int>(), ret);
        return ret;
    }
};

int main(void) {
    Solution s;
    char ch;
    int n = 0;
    while (cin >> ch) {
        if (ch == '[') {
            vector<int> candidates;
            int target;
            while (ch != ']') {
                int d;
                if (scanf("%d", &d)) {
                    candidates.push_back(d);
                }
                cin >> ch;
            }
            scanf("%*c%d", &target);
            vector<vector<int> > ret = s.combinationSum(candidates, target);
            cout << "case " << ++n << endl;
            for (int i = 0; i < ret.size(); i++) {
                for (int j = 0; j < ret[i].size(); j++) {
                    cout << ret[i][j] << " ";
                }
                cout << endl;
            }            
        }        
    }
    
    return 0;
}