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
    bool isMatch(const char *s, const char *p) {
        if (s == 0 || p == 0) {
            return s == p;
        }
        
        int i = 0, j = 0, ss = 0, sp = 0;
        int ls = strlen(s);
        int lp = strlen(p);
        bool any = false;
        while (i <= ls || j <= lp) {
            if (p[j] == '*') {
                any = true;
                ss = i;
                sp = j;
                i--;
            } else if (s[i] == 0 || (p[j] != '?' && p[j] != s[i])) {                
                if (any && j - sp + ss <= ls) {
                    j = sp;
                    i = ss++;
                } else {
                    break;
                }
            }
            i++;
            j++;
        }
        return s[i] == p[j];
    }
};

int main(void) {
    Solution sol;
    string buff;
    while (getline(cin, buff)) {
        string s, p;
        istringstream iss(buff);
        char ch;
        while (iss >> ch && ch != '"');
        while (iss >> ch && ch != '"') {
            s.push_back(ch);
        }
        while (iss >> ch && ch != '"');
        while (iss >> ch && ch != '"') {
            p.push_back(ch);
        }
        cout << (sol.isMatch(s.c_str(), p.c_str()) ? "true" : "false") << endl;
    }
    
    return 0;
}