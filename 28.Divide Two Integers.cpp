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
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 1;
        if (dividend > 0) {
            dividend = -dividend;
            flag = -flag;
        }
        if (divisor > 0) {
            divisor = -divisor;
            flag = -flag;
        }
        
        int result = 0;
        if (divisor == 0) {
            return 0;
        }
        
        int k = 0;
        for (; divisor >= (dividend + 1) >> 1; k++) {
            divisor <<= 1;
        }
        while (k >= 0 && dividend <= divisor) {
            dividend -= divisor;
            result += 1 << k;
            while (dividend > divisor) {
                divisor = (divisor + 1) >> 1;
                k--;
            }
        }
        
        return flag > 0 ? result : -result;
        //return dividend / divisor;
    }
};

int main(void) {
    Solution s;
    int a, b;
    while (cin >> a >> b) {
        cout << s.divide(a, b) << endl;
    }
    return 0;
}