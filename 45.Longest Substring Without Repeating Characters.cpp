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
    int lengthOfLongestSubstring(string s) {
        vector<bool> visit(256, false);
        size_t i = 0, j = 0;
        int maxlen = 0;
        while (j < s.length()) {
            while (j < s.length() && !visit[s[j]]) {
                visit[s[j++]] = true;
            }
            if (j - i > maxlen) {
                maxlen = j - i;
            }
            do {
                visit[s[i]] = false;
            } while (s[i++] != s[j]);
        }
        return maxlen;
    }
};

int main(void) {
    Solution s;
    string input;
    while (getline(cin, input)) {
        cout << s.lengthOfLongestSubstring(input.substr(1,input.length()-2)) << endl;
    }
    
    return 0;
}