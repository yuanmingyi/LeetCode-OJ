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
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 1) {
            return 0;
        }
                
        int pro = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                pro += prices[i] - prices[i-1];
            }
        }
        return pro;
    }
};

int main(void) {
    int n;
    Solution s;
    while (cin >> n) {
        vector<int> prices;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            prices.push_back(tmp);
        }
        cout << s.maxProfit(prices) << endl;
    }
    
    return 0;
}