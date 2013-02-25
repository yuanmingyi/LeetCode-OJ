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
    vector<vector<int> > ret;
    void perm(vector<int>& p, vector<int>& options, vector<bool>& used) {
        if (p.size() == options.size()) {
            ret.push_back(p);
            return;
        }
        
        for (size_t i = 0; i < options.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                p.push_back(options[i]);
                perm(p, options, used);
                p.pop_back();
                used[i] = false;
            }
        }
    }
    
public:
    
    vector<vector<int> > permute(vector<int> &num) {
        ret.clear();
        vector<int> p;
        vector<bool> used(num.size(), false);
        perm(p, num, used);
        return ret;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        istringstream iss(buff);
        vector<int> num;
        int d;
        char ch;
        while (iss >> ch >> d) {
            num.push_back(d);
        }
        
        vector<vector<int> > ret = s.permute(num);
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