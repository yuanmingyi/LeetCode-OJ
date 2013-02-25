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
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ss = S.length();
        int st = T.length();
        vector<int> count(st+1,0);
        count[0] = 1;
        for (int i = 0; i < ss; i++) {
            for (int j = st; j > 0; j--) {
                if (S[i] == T[j-1]) {
                    count[j] += count[j-1];
                }
            }
        }
        return count[st];
    }
};

int main(void) {
    Solution sol;
    string s, t;
    while (cin >> s >> t) {
        cout << sol.numDistinct(s.substr(1,s.length()-2), t.substr(1,t.length()-2)) << endl;
    }
    return 0;
}