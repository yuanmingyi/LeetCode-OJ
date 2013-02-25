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
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        vector<char> str(2*n+1,0);
        int k = 0, m = 0;
        while (k >= m) {
            while (k+m < 2*n) {
                if (k < n) {
                    str[k+m] = '(';
                    k++;
                } else {
                    str[k+m] = ')';
                    m++;
                }
            }
            ret.push_back(str.data());
            while (k > 0 && (k == m || str[k+m] != '(')) {
                if (str[k+m-1] == '(') {
                    k--;
                } else {
                    m--;
                }
            }
            str[k+m] = ')';
            m++;
        }
        return ret;
    }
};

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        vector<string> result = s.generateParenthesis(n);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}