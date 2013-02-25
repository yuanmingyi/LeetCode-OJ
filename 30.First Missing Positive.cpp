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
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            int t = i, s = A[t];
            while (s != t + 1 && s <= n && s > 0) {
                t = s - 1;
                s = A[t];
                A[t] = t + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (A[i-1] != i) {
                return i;
            }
        }
        return n + 1;
    }
};

int main(void) {
    Solution s;
    char ch;
    char buf[300];
    int A[1000];
    while (scanf("%c", &ch) == 1) {
        int n = 0;
        while (ch != ']') {
            int d;
            if (scanf("%d", &d) == 1) {
                A[n++] = d;
            }
            scanf("%c", &ch);
        }
        cout << s.firstMissingPositive(A, n) << endl;
        cin.getline(buf, sizeof(buf));
    }
    return 0;
}