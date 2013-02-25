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
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }        
        
        double r = pow(x, abs(n/2));
        double ans = n & 1 ? r*r*x : r*r;
        return n > 0 ? ans : 1.0/ans;
    }
};

int main(void) {
    Solution s;
    double x;
    int n;
    while (cin >> x >> n) {
        cout << s.pow(x, n) << endl;
    }
    return 0;
}