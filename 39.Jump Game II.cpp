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
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0, end = 0, nextend = 0, step = 0;
        while (end < n - 1) {
            if (A[start] + start > nextend) {
                nextend = A[start] + start;
            }
            if (start == end) {
                end = nextend;
                step++;
            }            
            start++;
        }
        return step;
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
        cout << s.jump(A.data(), A.size()) << endl;
        getline(cin, buf);
    }
    return 0;
}