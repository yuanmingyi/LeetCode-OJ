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
        int size = prices.size();
        if (size < 1) {
            return 0;
        }
        vector<int> maxpro(size,0);
        int minp = prices[0];
        for (int i = 1; i < size; i++) {
            if (prices[i] > minp) {
                maxpro[i] = prices[i] - minp;                
            } else {
                minp = prices[i];
            }
            if (maxpro[i] < maxpro[i-1]) {
                maxpro[i] = maxpro[i-1];
            }
        }
        int maxp = prices[size-1];
        for (int i = size-2; i >= 0; i--) {
            if (prices[i] < maxp) {
                maxpro[i] += maxp - prices[i];                
            } else {
                maxp = prices[i];
            }
            if (maxpro[i] < maxpro[i+1]) {
                maxpro[i] = maxpro[i+1];
            }
        }
        return maxpro[0];
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