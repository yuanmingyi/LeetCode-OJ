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
    string intToRoman(int num) {
        string ret;
        char *roman[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM", "", "", "", "", "", ""}};
        int ind = 0;
        while (num > 0) {
            int c = num % 10;
            num /= 10;
            ret = string(roman[ind++][c]) + ret;
        }
        return ret;
    }
};

int main(void) {
    int n;
    Solution s;
    while (cin >> n) {
        cout << s.intToRoman(n) << endl;
    }
    return 0;
}