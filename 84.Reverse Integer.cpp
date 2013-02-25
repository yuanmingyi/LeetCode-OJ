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
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        int y = 0;
        x = abs(x);
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y * sign;
    }
};

int main(void) {
    Solution s;
    int x;
    while (cin >> x) {
        cout << s.reverse(x) << endl;
    }
    return 0;
}