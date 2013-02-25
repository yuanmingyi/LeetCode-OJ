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
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0, end = 0;
        while (start <= end && end < n - 1) {
            if (A[start] + start > end) {
                end = A[start] + start;
            }
            start++;
        }
        return end >= n - 1;
    }
};

int main(void) {
    Solution s;
    char ch;
    string buf;
    while (cin >> ch) {
        vector<int> A;
        while (ch != ']') {
            int d;
            if (scanf("%d", &d)) {
                A.push_back(d);
            }
            cin >> ch;
        }
        cout << (s.canJump(A.data(), A.size()) ? "true" : "false") << endl;
        getline(cin, buf);
    }
    return 0;
}