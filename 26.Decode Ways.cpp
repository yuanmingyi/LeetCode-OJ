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
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0, count1 = 1, count2 = 1;
        for (int i = 0; i < s.length(); i++) {
            count = 0;
            if (s[i] >= '1' && s[i] <= '9') {
                count = count1;
            }
            if (i > 0 && 
                (s[i-1] == '1' && s[i] >= '0' && s[i] <= '9' ||
                s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                count += count2;
            }            
            count2 = count1;
            count1 = count;            
        }
        return count;
    }
};

int main(void) {
    Solution s;
    string str;
    while (std::getline(cin, str)) {
        cout << s.numDecodings(str) << endl;
    }
    return 0;
}