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
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> subset;
        vector<int> st;
        int p = 0;
        while (1) {
            if (p == S.size()) {
                ret.push_back(subset);                
                if (st.empty()) {
                    break;
                }
                p = st.back();                
                st.pop_back();
                while (p < subset.size() + st.size()) {
                    subset.pop_back();
                }                
                subset.push_back(S[p]);
            } else {
                st.push_back(p);
            }
            p++;
        }
        
        return ret;
    }
};

int main(void) {
    Solution s;
    string line;
    while (getline(cin, line)) {
        vector<int> S;
        int d;
        char ch;
        istringstream iss(line);
        while (iss >> ch >> d) {
            S.push_back(d);
        }
        vector<vector<int> > subsets = s.subsets(S);
        for (size_t i = 0; i < subsets.size(); i++) {
            cout << "[";
            for (size_t j = 0; j < subsets[i].size(); j++) {
                cout << subsets[i][j];
                if (j < subsets[i].size() - 1) cout << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
    return 0;
}