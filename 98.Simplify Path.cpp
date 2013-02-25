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
    string simplifyPath(string path) {
        vector<string> st;
        
        for (int i = 0, j = 0; i <= path.length(); i++) {
            if (path[i] == '/' || path[i] == 0) {
                string dir = path.substr(j, i - j);
                j = i;
                if (dir.empty() || dir == "/." || dir == "/") {
                    continue;
                }
                if (dir == "/..") {
                    if (!st.empty()) st.pop_back();
                } else {
                    st.push_back(dir);
                }
            }
        }
        
        string ret;
        for (int i = 0; i < st.size(); i++) {
            ret = ret + st[i];
        }
        
        return ret.empty() ? "/" : ret;
    }
};

int main(void) {
    Solution s;
    string line;
    while (cin >> line) {
        cout << s.simplifyPath(line.substr(1, line.length()-2)) << endl;
    }
    return 0;
}