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
    int longestValidParentheses(string s) {
        int max_length = 0;
        int valid = 0;
        int start = -1;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                valid++;
            } else if (s[i] == ')') {
                valid--;
            }
            if (valid == 0) {
                if (i - start > max_length) {
                    max_length = i - start;
                }
            } else if (valid < 0) {
                start = i;
                valid = 0;
            }
        }
        start = s.length();
        valid = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                valid++;
            } else if (s[i] == '(') {
                valid--;
            }
            if (valid == 0) {
                if (start - i > max_length) {
                    max_length = start - i;
                }
            } else if (valid < 0) {
                start = i;
                valid = 0;
            }
        }
        
        return max_length;
    }
};

int main(void) {
    Solution s;
    string input;
    while (getline(cin, input)) {
        cout << s.longestValidParentheses(input.substr(1, input.length()-2)) << endl;
    }
    
    return 0;
}