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
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_half = 0;
        string substr = "";
        for (size_t i = 0; i < s.length() - max_half; i++) {
            int j, k;
            for (j = i+1, k = i; j < s.length() && k >= 0 && s[j] == s[k]; j++, k--);
            if (j - k - 1 > substr.length()) {
                max_half = j - i - 1;
                substr = s.substr(k+1, j-k-1);
            }
            for (j = i+1, k = i-1; j < s.length() && k >= 0 && s[j] == s[k]; j++, k--);
            if (j - k - 1 > substr.length()) {
                max_half = j - i;
                substr = s.substr(k+1, j-k-1);
            }
        }
        
        return substr;
    }
};

int main(void) {
    Solution s;
    string input;
    while (getline(cin, input)) {
        string sub = s.longestPalindrome(input.substr(1,input.length()-2));
        cout << sub << endl;
    }
    return 0;
}