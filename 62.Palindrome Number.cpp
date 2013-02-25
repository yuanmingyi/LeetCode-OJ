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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int n = 1;
        while (n <= x / 10) n = n*10;
        for (int i = n; i > 1; i /= 100) {
            if (x % 10 != x / i) {
                return false;
            }
            x %= i;
            x /= 10; 
        }
        return true;
    }
};

int main(void) {
    Solution s;
    int x;
    while (cin >> x) {
        cout << (s.isPalindrome(x) ? "true" : "false") << endl;
    }
    return 0;
}