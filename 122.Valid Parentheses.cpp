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
    bool isValid(string s) {
        vector<char> st;
        int t = 0;
        while (t < s.length()) {
            if (s[t] == '[' || s[t] == '(' || s[t] == '{') {
                st.push_back(s[t]);
            } else if (s[t] == ']') {
                if (st.empty() || st.back() != '[') {
                    return false;
                }
                st.pop_back();
            } else if (s[t] == ')') {
                if (st.empty() || st.back() != '(') {
                    return false;
                }
                st.pop_back();
            } else if (s[t] == '}') {
                if (st.empty() || st.back() != '{') {
                    return false;
                }
                st.pop_back();
            }
            t++;
        }
        return st.empty();
    }
};

int main(void) {
    Solution s;
    string str;
    while (cin >> str) {
        cout << (s.isValid(str) ? "true" : "false") << endl;
    }
    return 0;
}