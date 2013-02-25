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

class Climb {
    vector<int> fib;
public:
    Climb():fib(2,1) {
    }
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0) {
            return 0;
        } 
        for (int i = fib.size(); i <= n; i++) {
            int f = fib[i-1] + fib[i-2];
            fib.push_back(f);
        }
        return fib[n];
    }
};

int main(void) {
    Climb c;
    int n;
    while (cin >> n) {
        cout << c.climbStairs(n) << endl;
    }
    return 0;
}