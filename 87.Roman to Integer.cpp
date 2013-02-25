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
    int romanToInt(string s) {
        string name = "IVXLCDM";
        int value[] = {1, 5, 10, 50, 100, 500, 1000};
        int len = sizeof(value)/sizeof(int);
        
        int val = 0;
        int last = 0;
        for (int i = 0; i < s.length(); i++) {
            int v = value[name.find(s[i])];
            if (v <= last) {
                val += last;
            } else {
                val -= last;
            }
            last = v;
        }
        val += last;
        return val;
    }
};

int main(void) {
    Solution s;
    string input;
    while (cin >> input) {
        cout << s.romanToInt(input.substr(1,input.length()-2)) << endl;
    }
    return 0;
}