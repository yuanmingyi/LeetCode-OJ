#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int z = x / 2;
        while (z > x / z) {
            z = (z + x/z) / 2;
        }
        return z;
    }
};

int main(void) {
    Solution s;
    int x;
    while (cin >> x) {
        cout << s.sqrt(x) << endl;
    }
    return 0;
}