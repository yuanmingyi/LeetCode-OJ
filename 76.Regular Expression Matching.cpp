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
        
        vector<bool> match(slen+1,false);
        match[0] = true;
        for (int i = 1; i <= plen; i++) {
            bool last = match[0];
            match[0] = last && (p[i] == '*');
            for (int j = 1; j <= slen; j++) {
                bool tmp = false;
                if (p[i] == '*') {
                    if (match[j]) { 
                        tmp = true;                         
                    } else if (match[j-1] && equal(s[j-1], p[i-1])) {
                        tmp = true;
                    }
                }
                if (last && equal(s[j-1], p[i-1])) {
                    tmp = true;
                }
                last = match[j];
                match[j] = tmp;
            }
            if (p[i] == '*') {
                i++;
            }
        }
        
        return match[slen];
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