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
    vector<vector<int> > feat1, feat2;
    
public:    
    bool areEqual(int b1, int b2, int e1, int e2) {        
        for (int i = 0; i < 256; i++) {
            if (feat1[e1][i] - feat1[b1][i] != feat2[e2][i] - feat2[b2][i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkScramble(int i, int j, int len, bool inv) {        
        for (int t = 1; t < len; t++) {
            if (inv && areEqual(i, j+len-t, i+t, j+len)) {
                return checkScramble(i, j+len-t, t, !inv) &&
                    (checkScramble(i+t, j, len-t, inv) || checkScramble(i+t, j, len-t, !inv));
            } else if (!inv && areEqual(i, j, i+t, j+t)) {
                return checkScramble(i, j, t, !inv) && 
                    (checkScramble(i+t, j+t, len-t, inv) || checkScramble(i+t, j+t, len-t, !inv));
            }
        }
        return len == 1;
    }
    
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        
        feat1 = vector<vector<int> >(len+1, vector<int>(256,0));
        feat2 = vector<vector<int> >(len+1, vector<int>(256,0));
        
        for (int i = 1; i <= len; i++) {
            feat1[i] = feat1[i-1];
            feat1[i][s1[i-1]]++;
            feat2[i] = feat2[i-1];
            feat2[i][s2[i-1]]++;
        }
        
        if (!areEqual(0,0,len,len)) return false;
        return checkScramble(0,0,len,true) || checkScramble(0,0,len,false);
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        char s1[1024], s2[1024];
        sscanf(buff.c_str(), "\"%[^\"]\", \"%[^\"]\"", s1, s2);
        cout << (s.isScramble(s1, s2) ? "true" : "false") << endl;
    }
    return 0;
}