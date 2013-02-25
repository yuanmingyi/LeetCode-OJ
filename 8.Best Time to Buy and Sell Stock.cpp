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

class MaxProfit {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 1) {
            return 0;
        }
        int minprice = prices[0];
        int maxpro = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minprice) {
                int pro = prices[i] - minprice;
                if (pro > maxpro) {
                    maxpro = pro;
                }
            } else {
                minprice = prices[i];
            }
        }
        return maxpro;
    }
};

int main(void) {
    MaxProfit p;
    int n;
    while (cin >> n) {
        vector<int> prices;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            prices.push_back(tmp);
        }
        cout << p.maxProfit(prices) << endl;
    }
    return 0;
}