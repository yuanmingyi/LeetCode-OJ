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
    bool equal(char a, char b) {
        return b == '.' ? a != 0 : a == b;
    }
    
    bool isMatch(const char *s, const char *p) {        
        if (s == 0 || p == 0) {
            return s == p;
        }
        
        int slen = strlen(s);
        int plen = strlen(p);
        
        vector<pair<int, int> > st;
        int i = 0, j = 0;
        
        while (i < slen || j < plen) {
            if (j < plen && p[j+1] == '*') {
                if (equal(s[i], p[j])) {
                    st.push_back(pair<int, int>(i, j));
                }
                j+=2;
            } else if (equal(s[i], p[j])) {
                i++;
                j++;
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    i = st.back().first + 1;
                    j = st.back().second;
                    st.pop_back();
                }
            }
        }
        return true;
    }
};

int main(void) {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        char s[1024], p[1024];
        sscanf(line.c_str(), "\"%[^\"]\", \"%[^\"]\"", s, p);
        cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    }
    return 0;
}