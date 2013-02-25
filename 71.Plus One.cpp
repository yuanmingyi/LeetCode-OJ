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
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;
        int c = 1;
        for (int i = digits.size() - 1; i >= 0 || c > 0; i--) {
            int val = c;
            if (i >= 0) {
                val += digits[i];
            }
            c = val / 10;
            val %= 10;
            ans.push_back(val);
        }
        for (size_t i = 0, j = ans.size()-1; i < j; i++, j--) {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

int main(void) {
    return 0;
}